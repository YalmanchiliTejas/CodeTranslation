#include<bits/stdc++.h>
const int maxn=200005;
using namespace std;
int a[maxn],b[maxn];
int main()
{
    int n,i,x,y;
   scanf("%d",&n);
   for(i = 1;i<=n;i++)
    scanf("%d",&a[i]),b[i]=a[i];
   sort(b+1,b+1+n);
   x=b[n/2];
   y=b[n/2+1];
   for(i = 1;i<=n;i++)
   {
       if(a[i]>x||a[i]==y) printf("%d\n",x);
       else if(a[i]<y||a[i]==x) printf("%d\n",y);

   }
}
