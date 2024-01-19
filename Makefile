CFLAGS+=-Wall -Wpedantic -Og

all: 8queens

8queens: main.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	@$(RM) *.o 8queens