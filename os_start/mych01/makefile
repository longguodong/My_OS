#This is a startup code.

startup.bin: startup.asm
	nasm startup.asm -o startup.bin
	dd if=startup.bin of=devfd0 bs=512 count=1
	bximage	
	dd if=startup.bin of=startup.img bs=512 count=1 conv=notrunc
	rm startup.bin devfd0
