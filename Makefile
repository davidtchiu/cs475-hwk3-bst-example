all: main.c bst.o 
	gcc -Wall -o bst main.c bst.o

bst.o: bst.h bst.c
	gcc -Wall -c bst.c

clean:
	rm -f bst *.o
