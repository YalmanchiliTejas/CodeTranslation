#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+100;
int a[2*maxn];
int main()
{
    int n,i,j,t;
    while (scanf("%d",&n)!=-1){
       t=n;i=maxn;j=maxn;
       for (t=1;t<=n;t++){
         if (t%2==1) scanf("%d",&a[j++]);
         else scanf("%d",&a[--i]);
       }
       if(n%2==0) {
        for (int k=i;k<j-1;k++) printf("%d ",a[k]);
        printf("%d\n",a[j-1]);
       } else {
         for (int k=j-1;k>i;k--) printf("%d ",a[k]);
         printf("%d\n",a[i]);
       }
    }
    return 0;
}
