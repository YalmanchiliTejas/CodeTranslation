#include<algorithm>
#include<cstdio>
#define N 101
#define p 1000000007
#define ll long long
using namespace std;
inline int mod(int x){return x<p?x:x-p;}
inline int calc(int x,int y)
{
    int z=1;
    for(;y;x=(ll)x*x%p,y>>=1)if(y&1)z=(ll)x*z%p;
    return z;
}
int a[N],b[N],d[N],e[N],f[2][N],g[N],h,i,j,n;
inline bool cmp(int u,int v){return a[u]<a[v];}
inline int mul(int u,int v){return(ll)d[v]*e[u]%p;}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i),b[i]=i;
    sort(b+1,b+n+1,cmp);
    for(i=1;i<=n;a[b[i++]]=h)if(a[b[i]]!=g[h])g[++h]=a[b[i]];
    for(i=0;i<=n;i++)e[i]=calc(d[i]=calc(2,g[i]),p-2);
    for(i=1,*f[0]=mod(p+d[a[1]]-mod(mul(1,a[1])<<1)),f[0][a[1]]=2;i<a[1];i++)f[0][i]=mod(mod(p+mul(i,a[1])-mul(i+1,a[1]))<<1);
    for(i=2;i<=n;i++)
    if(a[i-1]<a[i])
    {
        for(j=0;j<a[i-1];f[i&1][j++]=0)f[i&1^1][j]=(ll)f[i&1][j]*mul(a[i-1],a[i])%p;
        for(f[i&1^1][a[i]]=h=mod(f[i&1][j=a[i-1]]<<1),f[i&1][j]=0;j<a[i];j++)f[i&1^1][j]=(ll)h*(p+mul(j,a[i])-mul(j+1,a[i]))%p;
    }
    else
    {
        for(j=0;j<a[i];f[i&1][j++]=0)f[i&1^1][j]=f[i&1][j];
        for(j=a[i];j<=a[i-1];f[i&1][j++]=0)f[i&1^1][a[i]]=mod(f[i&1^1][a[i]]+mod(f[i&1][j]<<1));
    }
    for(i=j=0;i<=a[n];i++)j=mod(j+f[n&1^1][i]);
    return 0&printf("%d\n",j);
}