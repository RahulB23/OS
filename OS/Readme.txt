Setup docker for building:
docker build buildenv -t myos-buildenv

Run docker container for building: 
docker run --rm -it -v %cd%:/root/env os_buildenv

Make project:
make build-x86_64

Emulate in qemu for x86_64:
qemu-system-x86_64 -L "C:\Program Files\qemu" -cdrom dist/x86_64/kernel.iso