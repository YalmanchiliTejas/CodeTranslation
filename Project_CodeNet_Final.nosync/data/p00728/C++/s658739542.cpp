#include <stdio.h>
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int min(int a,int b){
    if(a>b)return b;
    return a;
}
int main(){
    int n,top,bot,tot,temp;
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        scanf("%d",&top);
        tot=bot=top;
        for(int i=1;i<n;i++){
            scanf("%d",&temp);
            tot+=temp;
            top=max(top,temp);
            bot=min(bot,temp);
        }
        printf("%d\n",(tot-top-bot)/(n-2));
    }
}