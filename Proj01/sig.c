#include "csapp.h"

int counter = 0;

void handler(int sig)
{
counter++;
printf("sig!"); /* Do some work in the handler */
getchar();
return;
} 
  
int main()
{
int i;
 
Signal(SIGINT, handler);
Signal(SIGTSTP, handler);
 
if (Fork() == 0) { /* Child */
for (i = 0; i < 5; i++) {
Kill(getppid(), SIGINT);
printf("sent SIG to parent\n");
}
exit(0);
}
 
Wait(NULL);
printf("counter=%d\n", counter);
getchar();
exit(0);
}
