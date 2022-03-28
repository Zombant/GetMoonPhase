install:
	gcc get-moon-phase.c -lm -o get-moon-phase.o
	cp get-moon-phase.o ~/.local/bin/
