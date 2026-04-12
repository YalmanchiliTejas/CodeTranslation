#include <stdio.h>
#include <string.h>

void push(int p,char c);
void pop(int p);
void fmove(int p,int q);
char block[101][1001];//ブロックの状態[山][高さ]

int main(void){
    int n,p,q;
    char op[5],c;//命令,色
    scanf("%d",&n);
    //初期化
    for(int i=0;i < n;i++){
        memset(block[i],'\0',1000);
    }
    //るぅぷ
    while(1){
        scanf("%s",op);
        if(strcmp(op,"quit") == 0)break;
        if(strcmp(op,"push") == 0){
            scanf("%d %c",&p,&c);
            push(p,c);
        }
        if(strcmp(op,"pop") == 0){
            scanf("%d",&p);
            pop(p);
        }
        if(strcmp(op,"move") == 0){
            scanf("%d %d",&p,&q);
            fmove(p,q);
        }
    }
    return 0;
}

void push(int p,char c){
    block[p-1][strlen(block[p-1])]=c;
    return;
}

void pop(int p){
    printf("%c\n",block[p-1][strlen(block[p-1])-1]);
    block[p-1][strlen(block[p-1])-1]='\0';
    return;
}

void fmove(int p,int q){
    block[q-1][strlen(block[q-1])]=block[p-1][strlen(block[p-1])-1];
    block[p-1][strlen(block[p-1])-1]='\0';
    return;
}