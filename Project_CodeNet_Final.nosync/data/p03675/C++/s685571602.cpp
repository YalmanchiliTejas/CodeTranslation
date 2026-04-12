#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int a[maxn],ans[maxn];
int n;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
   }
   int l=1,r=n,k=n,cnt=1;
   for(int i=1;i<=n;i++){
        if(cnt&1)
            ans[l++]=a[k--];
        else
            ans[r--]=a[k--];
        cnt++;
   }
   for(int i=1;i<=n-1;i++)
    printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
}
/*
1 2 3 4
4 2 1 3

0 6 7 6 7 0
0 6 6 0 7 7
*/
