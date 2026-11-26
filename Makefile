.PHONY: all run clean

CC = gcc
CFLAGS = -Wall -Wextra

all: build/main

build/main: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) src/main.c -o build/main

run: build/main
	./build/main

clean:
	rm -rf build
