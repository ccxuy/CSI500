/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

/* function prototypes */
void eval(char *cmdline);

int main() 
{
    char cmdline[MAXLINE]; /* Command line */

    while (1) {
        /* Read */
        system("clear");
        printf("\n");                   
        printf("=======START========\n");                   
        printf("Welcome to My Shell!\n");                   
        printf("There is several options avaliable.\n");    
        printf("1. program 1.\n");                   
        printf("========END=========\n");                   
        Fgets(cmdline, MAXLINE, stdin); 
        if (feof(stdin))
            exit(0);

        /* Evaluate */
        eval(cmdline);

        /* Wait for continue*/
        printf("\n\nPress any key to continue...");
        getchar();
    } 
}
/* $end shellmain */
  
/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
   
    //printf("cmd: %s",cmdline); 
    printf(",%d\n",strcmp(cmdline, "quit"));
    if (!strcmp(cmdline, "quit\n")) /* quit command */
    {
        exit(0);
    }
    
    if (!strcmp(cmdline, "1\n"))    /* Run program 1*/
    {
        printf("cmd 1 received!\n");
        
        pid = Fork(); //line:ecf:forkreturn
        if (pid == 0) {  /* Child */
            execve("prog1", NULL, environ);
        }
    }

    int status;
    waitpid(pid, &status, 0);
    //unix_error("waitfg: waitpid error");

    return;
}
/* $end eval */
