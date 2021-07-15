# Rotate Luks Key

Rotate LUKS key is a small tool I came up with because someone
super annoying somewhere came up with a requirement that all
physical Linux servers have to have full disk encryption with
keys being rotated every quarter. I hate manually doing 
things like that So I came up with this tool to change keys on 
thousands of physical servers using Ansible in seconds.

## How it works
This tool uses the API in the cryptsetup development package to
bind to a block device and change a key. To compile, the 
cryptsetup-devel package must be installed. (May be called 
something differently on Debian based distros)

## Requirements
- Obviously have Linux servers that use LUKS
- Modern C++ compiler
- Cryptsetup-devel installed (may be called something else debian based distros)
- Packages to use Makefiles
- A text editor

## Instructions
( I highly recommend testing this on a single machine before trying
to change thousands of servers at once, I've only tested this on
RHEL 7/8 and Fedora 32/33/34)
1. Clone the repository
```sh
git clone https://github.com/patrick-93/rotateLuksKey.git
```

2. Edit the rotateLuksKey.cpp file and go down the line labeled "LINE TO CHANGE"

3. Change the line below the comments to have your old keyslot 
number, new keyslot number, old password, old password length, 
new password, and new password length

4. Save your changes
5. Compile the new source file
```sh
make
```
6. Confirm it worked

7. Edit the rotateLuksKey.cpp, remove your old and new passphrase, save 
the changes

8. Push this newly compiled binary out to servers and run as root
