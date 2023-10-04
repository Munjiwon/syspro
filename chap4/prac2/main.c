#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define MAXLINE 80
/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[MAXLINE];
    int i=1;
    int opt,n; //option이 있는지 검사용
    int line=1;

    if (argc < 2){
        fp = stdin;
        exit(1);
    }
    while((opt=getopt(argc,argv,"n"))!=-1){
        switch(opt){
            case 'n':
                n=1;
                break;
        }
    }
    if(n==1){
        while(argv[i+1]!=NULL) {
            fp = fopen(argv[i+1], "r");
            while (fgets(buffer,MAXLINE,fp)!=NULL) {
                printf("%3d %s",line,buffer);
                line++;
            }
            fclose(fp);
            i++;
        }
    }
    else{
        while(argv[i]!=NULL) {
            fp = fopen(argv[i], "r");
            while (fgets(buffer,MAXLINE,fp)!=NULL) {
                printf("%s",buffer);
            }
            fclose(fp);
            i++;
        }
    }
    return 0;
}
