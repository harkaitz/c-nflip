#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>

char const
help[] =
    "Usage: nflip [-f][-e] < NUMBERS > NUMBERS"                      "\n"
    ""                                                               "\n"
    "Flip the sign of the numbers read from the standard input. The" "\n"
    "input can contain other characters."                            "\n"
    ""                                                               "\n"
    "  -f : Flip number signs."                                      "\n"
    "  -e : Transform to the spanish number notation."               "\n"
    ""                                                               "\n"
    "Copyright (c) 2024, Harkaitz Agirre, all rights reserved."      "\n"
    ;

static void
nflip(char _b[], bool _flip, bool _spanish);

int
main(int _argc, char *_argv[])
{
	int	chr;
	int	opt;
	bool	opt_f = false;
	bool	opt_e = false;
	char	number[512];
	size_t	numbersz = 0;
	bool	negative = false;
	bool	digits = false;
	char	prev = ' ';
	
	if (_argc > 1 && (!strcmp(_argv[1], "--help") || !strcmp(_argv[1], "-h"))) {
		fputs(help, stdout);
		return 0;
	}
	
	while ((opt = getopt (_argc, _argv, "fe")) != -1) {
		switch (opt) {
		case 'f': opt_f = true; break;
		case 'e': opt_e = true; break;
		case '?':
		default:
			return 1;
		}
	}
	if (!opt_f && !opt_e) {
		opt_f = true;
	}
	
	while (true) {
		chr = fgetc(stdin);
		
		// Negative sign.
		if (chr != EOF && !digits && !negative && chr == '-') {
			number[numbersz++] = chr;
			negative = true;
			continue;
		}
		
		// Spaces.
		if (chr != EOF && !digits && !negative && chr == ' ') {
			number[numbersz++] = chr;
			prev = ' ';
			continue;
		}
		
		// Digits.
		if (chr != EOF && strchr("0123456789.", chr)) {
			number[numbersz++] = chr;
			digits = true;
			continue;
		}
		
		// Print block when needed.
		if (numbersz > 0 && digits && strchr(" \t\n\r", prev) && (chr == EOF || !strchr("-/", chr))) {
			number[numbersz++] = '\0';
			nflip(number, opt_f, opt_e);
		} else if (numbersz > 0) {
			fwrite(number, 1, numbersz, stdout);
		}
		numbersz = 0;
		negative = digits = false;
		if (chr == EOF) {
			return 0;
		} else {
			prev = chr;
			fputc(chr, stdout);
		}
	}
	
	return 0;
}

static void
nflip(char _b[], bool _flip, bool _spanish)
{
	int	i;
	size_t	l = strlen(_b);
	char	b[l+3];
	int	space = -1;
	int	number = -1;
	int	digit = -1;
	
	/* Search number and space in _b. */
	for (i=0; _b[i]; i++) {
		if (digit == -1 && number == -1 && _b[i] == ' ') {
			space = i;
		}
		if (digit == -1 && strchr("0123456789", _b[i])) {
			digit = i;
		}
		if (number == -1 && strchr("-0123456789", _b[i])) {
			number = i;
		}
	}
	
	/* Without a number simply print. */
	if (digit == -1) {
		fputs(_b, stdout);
		return;
	}
	
	/* Flip when needed. */
	if (_flip && _b[number]=='-') {
		strcpy(b, _b);
		b[number] = ' ';
	} else if (_flip && space == -1) {
		b[0]='-';
		strcpy(b+1, _b);
	} else if (_flip && space != -1) {
		strcpy(b, _b);
		b[space] = '-';
	} else {
		strcpy(b, _b);
	}
	
	/* Transform into spanish notation. */
	if (_spanish) {
		for (i=0; b[i]; i++) {
			if (b[i]=='.') {
				b[i]=',';
			} else if (b[i]==',') {
				b[i]='.';
			}
		}
	} 
	fputs(b, stdout);
}
