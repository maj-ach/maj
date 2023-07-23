CC = gcc

FLAGS = -std=c11 -Wall -Wextra -pedantic -g

OBJECTS = main.o init.o terminal_setup.o addl_funcs.o input.o output.o open_directory.o autocomplete.o determine_program_status.o open_file.o

maj: $(OBJECTS)
	$(CC) $(OBJECTS) -o maj $(FLAGS)

main.o: header.h 
	$(CC) -c main.c -o main.o $(FLAGS)

init.o: structs.h defines.h 
	$(CC) -c init.c -o init.o $(FLAGS)

terminal_setup.o: structs.h addl_funcs.h
	$(CC) -c terminal_setup.c -o terminal_setup.o $(FLAGS)

addl_funcs.o: structs.h defines.h
	$(CC) -c addl_funcs.c -o addl_funcs.o $(FLAGS)

input.o: structs.h defines.h addl_funcs.h
	$(CC) -c input.c -o input.o $(FLAGS)

output.o: structs.h defines.h addl_funcs.h
	$(CC) -c output.c -o output.o $(FLAGS)

open_directory.o: structs.h defines.h openfile.h addl_funcs.h
	$(CC) -c open_directory.c -o open_directory.o $(FLAGS)

autocomplete.o: structs.h defines.h addl_funcs.h
	$(CC) -c autocomplete.c -o autocomplete.o $(FLAGS)

determine_program_status.o:
	$(CC) -c determine_program_status.c -o determine_program_status.o $(FLAGS)

open_file.o:
	$(CC) -c open_file.c -o open_file.o $(FLAGS)
