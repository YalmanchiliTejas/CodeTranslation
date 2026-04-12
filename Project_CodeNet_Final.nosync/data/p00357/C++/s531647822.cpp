#include <stdio.h>
const int N=1e6+10;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main(){
    int n,l=1,r,a[N];
    scanf("%d",&n);
    r=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]/=10;
    }
    for(int i=1;i<=n;i++)if(l>=i)l=max(l,a[i]+i);
    else {
        printf("no\n");
        return 0;
    }
    for(int i=n;i>=1;i--)if(r<=i)r=min(r,i-a[i]);
    else {
        printf("no\n");
        return 0;
    }
    printf("yes\n");
}
