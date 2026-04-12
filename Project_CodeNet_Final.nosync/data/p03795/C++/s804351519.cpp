#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int my_gets(char *buf,int nBuf,FILE *fp){
    int ch;

    while(--nBuf >0){
        ch=getc(fp);
        if(ch==EOF || ch=='\n')
            break;
        *(buf++)=(char)ch;
    }
    *(buf)='\0';

    return nBuf;
}

int main(){
    int N;

    scanf("%d",&N);
    printf("%d\n", N*800 - (N/15)*200);
    
    return 0;
}