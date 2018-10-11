All: Node.o
	gcc Node.o

Pizza.o: Node.c
	gcc -c Node.c

run:
	./a.out

clean:
	rm *.o
	rm *.out
