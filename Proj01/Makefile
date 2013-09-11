
all : student_message fork project1 interact mshell shellex prog1

CC = gcc
CFLAGS = -g 

interact : interact.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ interact.o csapp.o

shellex : shellex.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ shellex.o csapp.o

prog1 : prog1.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ prog1.o csapp.o

mshell : mshell.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ mshell.o csapp.o

fork : fork.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ fork.o csapp.o

%.o : %.c csapp.h
	$(CC) $(CFLAGS) -c $<  

project1 : project1.o csapp.o
	$(CC) $(CFLAGS) -lpthread -o $@ project1.o csapp.o



.phoney : student_message
student_message :
	echo It is YOUR JOB to make sure and maybe reconfigure this Makefile so make builds your Project 01 software!

.phoney : clean
clean :
	rm -f *.o fork project1 mshell shellex prog1
