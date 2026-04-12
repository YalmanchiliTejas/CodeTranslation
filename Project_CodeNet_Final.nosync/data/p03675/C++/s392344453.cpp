#include<cstdio>

#define  N 1000005

using namespace std;

int a[N],vis[N],i,n;
int main()
{
       scanf("%d",&n);
       for (i=1;i<=n;++i) scanf("%d",&a[i]);
       for (i=n;i>=1;i-=2) vis[i]=1,printf("%d ",a[i]);
       for (i=1;i<=n;++i) if (!vis[i]) printf("%d ",a[i]);
}