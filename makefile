CC=gcc
CFLAGS=-I.
DEPS = array.h menu.h operate.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

array: main.o menu.o array.o operate.o
	gcc -o array main.o menu.o array.o operate.o -I.
