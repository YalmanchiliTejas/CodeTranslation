#include <stdio.h>
int main(){
    int a[5],b[5],top,pos;
    while(true){
        for(int i=0;i<5;i++){
            scanf("%d%d",&a[i],&b[i]);
            if(i==0&&a[i]==0&&b[i]==0)return 0;
            a[i]+=b[i];
            if(i==0){
                pos=0;
                top=a[i];
            }
            else if(a[i]>top){
                top=a[i];
                pos=i;
            }
        }
        printf("%c %d\n",'A'+pos,top);
        
    }
}
