#include <iostream>
#include "libcryptsetup.h"

using std::cout;
using std::cin;
using std::endl;

int rotate_key(char *device);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: rotateLuksKey </dev/device>\nExample: ./rotateLuksKey /dev/sda2" << endl;
	}
	return rotate_key(argv[1]);
}

int rotate_key(char *device) {
	struct crypt_device *cd;
	int r = 0;
	r = crypt_init(&cd, device);

	if (r < 0) {
		printf("crypt_init() failed, are you sure that's a LUKS encrypted disk?\n");
		exit(1);
	}
	else {
		printf("Context has attached to block device %s\n",
			crypt_get_device_name(cd)
		);
	}
	
	r = crypt_load(cd, CRYPT_LUKS, NULL);
	r = crypt_keyslot_change_by_passphrase(
		cd, 0, 0, "secret_old_pw", 13, "secret_new_pw", 13
	);

	if (r < 0) {
		printf("Changed the passphrase failed");
		return r;
	}
	else {
		return r;
	}
}
