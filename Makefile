CFLAGS=-std=c11 -g -static

minic: minic.c

test: minic
	./test.sh

clean:
	rm -f minic *.o *~ tmp*

.PHONY: test clean
