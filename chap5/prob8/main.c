#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char savedText[10][100]={'\0'};
    int fd;
    char num[8];
    char buf;

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        printf("파일 열기 오류\n");
        exit(2);
    }
    else{
        printf("File read success\n");
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<100;j++){
            read(fd,&buf,1);
            savedText[i][j]=buf;
            if(buf=='\n'){
                break;
            }
            else if(buf=='.'){
                savedText[i][j+1]='\n';
                break;
            }
        }
    }
    printf("Total Line : 4\n");
    printf("You can choose 1 ~ 4 Line\n");
    printf("Pls 'Enter' the line to select : ");

    scanf("%s",num);
    if(num[0]==42){
        for(int i=0;i<4;i++){
            printf("%s",savedText[i]);
        }
    }
    else if(num[1]=='\0'){
        int a=num[0]-49;
        printf("%s",savedText[a]);
    }
    else if(num[1]==','){
        for (int i=0;i<8;i+=2){
            int a=num[i]-49;
            printf("%s",savedText[a]);
        }
    }
    else if(num[1]=='-'){
        for(int i=num[0]-49;i<=num[2]-49;i++){
            printf("%s",savedText[i]);
        }
    }

    close(fd);
    exit(0);
}
