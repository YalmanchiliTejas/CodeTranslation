#include <stdio.h>
#include <algorithm>
int a[200005];
int b[200005];
int main(){
    int n,v,mid;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        a[i]=v;
        b[i]=v;
    }
    std::sort(b,b+n);
    mid = b[n/2-1];
    for(int i=0;i<n;i++){
        if(a[i]>mid){
          printf("%d\n",mid);
        }else{
            printf("%d\n",b[n/2]);
        }

    }
}
