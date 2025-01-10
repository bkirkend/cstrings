CC= gcc
CFLAGS= -Werror
EXE= out
SOURCES= test.c \
				 string.c

$(EXE): clean
	$(CC) $(SOURCES) $(CFLAGS) -o $@

memory: $(EXE)
	leaks --atExit -- ./$(EXE)

clean: 
	rm -f *.o out

