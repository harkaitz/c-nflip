.POSIX:
.SUFFIXES:
.PHONY: all clean install check
all:
PROJECT   =c-nflip
VERSION   =1.0.0
CC        =gcc -Wall -g3 -std=c99
PREFIX    =/usr/local
BUILDDIR ?=.build
PROGS     =$(BUILDDIR)/nflip$(EXE)

all: $(PROGS)
clean:
	rm -f $(BUILDDIR)/nflip$(EXE)
install: $(PROGS)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(PROGS) $(DESTDIR)$(PREFIX)/bin
check:

$(BUILDDIR)/nflip$(EXE): nflip.c
	$(CC) $(CFLAGS) -o $@ $<

## -- BLOCK:c --
clean: clean-c
clean-c:
	rm -f *.o
## -- BLOCK:c --
