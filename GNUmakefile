.POSIX:
.SUFFIXES:
.PHONY: all clean install check
all:
PROJECT   =c-nflip
VERSION   =1.0.0
CC        =gcc -Wall -std=c99
PROGS     =$(BUILDDIR)/nflip$(EXE) 
PREFIX    =/usr/local
BUILDDIR ?=/home/harkaitz/.build

all: $(PROGS)
clean:
	rm -f $(BUILDDIR)/nflip$(EXE)
install: $(PROGS)
	mkdir -p $(PREFIX)/bin
	cp $(PROGS) $(PREFIX)/bin
check:

$(BUILDDIR)/nflip$(EXE): nflip.c
	$(CC) $(CFLAGS) -o $@ $<

## -- BLOCK:c --
clean: clean-c
clean-c:
	rm -f *.o
## -- BLOCK:c --
