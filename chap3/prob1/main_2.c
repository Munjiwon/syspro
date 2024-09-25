#include <stdio.h>
#include "copy_2.h"

char line[MAXLINE];
char longest[MAXLINE];


main(){
  int len;
  int max;
  max = 0;

  while(gets(line) != NULL) {
    len = strlen(line);

    if(len > max) {
       max = len;
       copy(line, longest);
      }
    }

  if(max > 0) // 입력 줄이 있었다면
    printf("%s \n", longest);

  return 0;
}

