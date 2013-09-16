/* $begin shellmain */
#include "csapp.h"
#include <termios.h>  
#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)  
#define MAXARGS   128

/* function prototypes */
void eval(char *cmdline);
void handler(int sig);
int counter = 0;

int main() 
{
    char cmdline[MAXLINE]; /* Command line */

    Signal(SIGINT, handler);
    Signal(SIGTSTP, handler);

    while (1) {
        /* Read */
        system("clear");
        printf("\n");                   
        printf("=======START========\n");                   
        printf("Welcome to My Hospital!\n");                   
        printf("There are several options avaliable.\n");    
        printf("1: checkin.\n");                   
        printf("2: diagnosis.\n");                   
        printf("3: checkout.\n");                   
        printf("help: program 1.\n");                   
        printf("info: check version and who made it\n");                   
        printf("quit: exit shell.\n");                 
        printf("========END=========\n");                   
        Fgets(cmdline, MAXLINE, stdin); 
        if (feof(stdin))
            exit(0);

        /* Evaluate */
        eval(cmdline);

        /* Wait for continue*/
        printf("\n\nPress ENTER key to continue...");
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
    //printf(",%d\n",strcmp(cmdline, "quit"));
    if (!strcmp(cmdline, "quit\n")) /* quit command */
    {
        char passwd[20];
        getpasswd(passwd, sizeof(passwd));
        if(!strcmp(passwd, "IAmTheBoss\n")){
            exit(0);
        }
        printf("\nWrong password!");
    }
    else if (!strcmp(cmdline, "1\n"))    /* Run program 1*/
    {
        printf("cmd 1 received!\n");
        Sleep(1); 
        system("clear");
        pid = Fork(); //line:ecf:forkreturn
        if (pid == 0) {  /* Child */
            execve("prog1", NULL, environ);
        }
    }
    else if (!strcmp(cmdline, "2\n"))    /* Run program 1*/
    {
        printf("cmd 2 received!\n");
        
        Sleep(1); 
        system("clear");
        pid = Fork(); //line:ecf:forkreturn
        if (pid == 0) {  /* Child */
            execve("prog2", NULL, environ);
        }
    }
    else if (!strcmp(cmdline, "3\n"))    /* Run program 1*/
    {
        printf("cmd 3 received!\n");
        
        Sleep(1); 
        system("clear");
        pid = Fork(); //line:ecf:forkreturn
        if (pid == 0) {  /* Child */
            execve("prog3", NULL, environ);
        }
    }
    else if (!strcmp(cmdline, "help\n"))    /* Run program 1*/
    {
        Sleep(1); 
        system("clear");
        printf("help information:\n");
        printf("Type 1 first to checkin a patient.\n");
        printf("Then type 2 to diagnosis the patient.\n");
        printf("Afterwards, type 3 to checkout the patient.\n");
        printf("\n");
        printf("If you want to quit, type \"quit\" and then type password \"IAmTheBoss\"\n");
    }
    else if (!strcmp(cmdline, "info\n"))    /* Run program 1*/
    {
        Sleep(1); 
        system("clear");
        printf("Version: 1.0\n");
        printf("Author: Yihang Xu\n");
    }
    else{
        printf("no such command!");
    }
    int status;
    waitpid(pid, &status, 0);
    //if (errno != ECHILD)
    //    unix_error("waitfg: waitpid error");

    return;
}
/* $end eval */


int getpasswd(char* passwd, int size)  
{  
   int c;  
   int n = 0;  
    
   printf("Please Input password:\n");  
    
   set_disp_mode(STDIN_FILENO,0);
   do{  
      c=getchar();  
      if (c != '\n'|c!='\r'){  
         passwd[n++] = c;  
      }  
   }while(c != '\n' && c !='\r' && n < (size - 1));  
   passwd[n] = '\0';  
   set_disp_mode(STDIN_FILENO,1);
   return n;  
}


int set_disp_mode(int fd,int option)  
{  
   int err;  
   struct termios term;  
   if(tcgetattr(fd,&term)==-1){  
     perror("Cannot get the attribution of the terminal");  
     return 1;  
   }  
   if(option)  
        term.c_lflag|=ECHOFLAGS;  
   else  
        term.c_lflag &=~ECHOFLAGS;  
   err=tcsetattr(fd,TCSAFLUSH,&term);  
   if(err==-1 && err==EINTR){  
        perror("Cannot set the attribution of the terminal");  
        return 1;  
   }  
   return 0;  
}

 
void handler(int sig)
{
counter++;
printf(""); /* Do some work in the handler */
return;
} 
