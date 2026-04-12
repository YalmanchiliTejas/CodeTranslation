#include <stdio.h>
 
void swap(int* a,int* b){
    int po=*a;
    *a=*b;
    *b=po;
}
 
int seiretu(int* p,int N){
    for(int i=0;i<N;i++)if(p[i]!=i)return 0;
    return 1;
}
 
int main(void){
    int N;
    int count=0;
    int po[114514];
    scanf("%d",&N);
    int p[N];
    for(int i=0;i<N;i++)scanf("%d",&p[i]);
    while(seiretu(p,N)==0){
        if(p[0]<p[N-1]&&!(p[0]==0&&p[N-1]==N-1)){po[count]=N-1;count++;swap(&p[0],&p[N-1]);}
        for(int i=0;i<N-1;i++)swap(&p[i],&p[i+1]);po[count]=1;count++;
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)printf("%d\n",po[i]);
    return 0;
}