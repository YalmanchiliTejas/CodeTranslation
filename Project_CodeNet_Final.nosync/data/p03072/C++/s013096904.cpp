#include<stdio.h>
#define MAXN 100015

int a[MAXN];

int main(){

   /* freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);*/
    int n,i,ans=0,maxn=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=maxn)maxn=a[i],ans++;
    }
    printf("%d",ans);
    return 0;

}