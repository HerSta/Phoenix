#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sverresnetwork.h"
#include <time.h>
#include <string.h>

int time_ref = 0;
int i = 0;

int powerolini(int base, int exponent){
  int sum = base;
  if (exponent == 0) {
    return 1;
  }
  for(int i = 1; i < exponent; i++){
    sum *= base;
  }
  return sum;
}

int strToNum(char* str){
  int sum = 0;
  for(int i = 0; i<strlen(str);i++){
    sum += (str[strlen(str) - i - 1] - '0')*powerolini(10,i);
  }
  return sum;
}

void udpmessageReceived(const char * ip, char * data, int datalength){
  //printf("You have wasted this much time: %s seconds. Courtesy of: '%s'\n",data,ip);
  i = strToNum(data);
  time_ref = time(NULL);
}

int main()
{

  int time_to_wait = 2;
  time_ref = time(NULL);
  udp_startReceiving(4321,udpmessageReceived);

  printf("The system will now wait %d seconds\n",time_to_wait);
  while (time(NULL) - time_ref < time_to_wait){
  }

  char cwd[1024];
  //getcwd(cwd, sizeof(cwd));
  //THIS PATH MUST OBVISOULY BE CHANGED
  strcpy(cwd,"/Users/God/Downloads/exercise6-team-master/Phoenix");
  
  char command[2048];
  strcat(command, "osascript -e 'tell app \"Terminal\" to do script [\"");
  strcat(command, cwd);
  strcat(command, "/./Phoenix\"]\'");

  //printf("%s\n", command);
 
  system(command);

  while(1)
  {
    i++;
    char p[6]; //forskjell på * og []. Les om dette herman.
    sprintf(p,"%d",i);
    udp_broadcast(4321,p,6); //first argument is port
    printf("You have wasted this much time: %d seconds.\n",i);
    sleep(1);
  }


  return 0;
}



//system() vs fork()
//int status = system("./Phoenix 1 2 3");
