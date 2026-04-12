#include<stdio.h>
int main(){
    int ary[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&ary[i]);
    int maxnum=0,gt=0;
    for(int i=0;i<n;i++){
        if(ary[i]>=maxnum){
            maxnum=ary[i];
            gt++;
        }
    }
    printf("%d\n",gt);
    return 0;
}