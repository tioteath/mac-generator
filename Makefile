all:
	gcc -static -o mac-generator main.c

install:
	cp mac-generator /bin/
