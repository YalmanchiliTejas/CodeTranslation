#include<stdio.h>
int main(){
    int N;
    int mou[20];
    int now=0;
    int count=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&mou[i]);
        if(now<=mou[i]){
            count++;
            now=mou[i];
        }
    }
    printf("%d\n",count);
}