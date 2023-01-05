CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

minic: $(OBJS)
	$(CC) -o minic $(OBJS) $(LDFLAGS)

$(OBJS): minic.h

test: minic
	./test.sh

clean:
	rm -f minic *.o *~ tmp*

.PHONY: test clean
