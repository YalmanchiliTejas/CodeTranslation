#include<bits/stdc++.h>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 200010
#define maxm 100010
#define inf 1000000007
#define mod 1000000007
#define pi acos(-1)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef bitset<maxn> bit;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
char s[maxn];
int a[maxn];
bool check()
{
    for(int i=1;i<=m;i++)  if(a[i])  return false;
    return true;
}
int g[maxn],f[maxn],sum[maxn][2];
int L=inf;
int main()
{
    n=read();m=read();
    scanf("%s",s+1);
    for(int i=1;i<=m;i++)  a[i]=(s[i]=='B');
    if(a[1])  for(int i=1;i<=m;i++)  a[i]^=1;
    if(check())
    {
        if(n==2) return puts("3"),0;
        g[0]=1;g[1]=2;
        for(int i=2;i<=n;i++)  g[i]=(g[i-1]+g[i-2])%mod;
        return printf("%d\n",(g[n-1]+g[n-3])%mod),0;
    }
    for(int i=1;i<=m;i++)
    {
        if(a[i])  continue;
        int R=i;
        while(R<m&&!a[R+1])  R++;
        if(R==m)  break;
        if(i==1)  L=min(L,R-i+2);
        if((R-i+1)&1)  L=min(L,R-i+1);
        i=R;
    }
    f[0]=1;sum[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i>=2)
        {
            f[i]=sum[i-2][i&1];
            if(i>=L+2)  f[i]=(f[i]-sum[i-L-2][i&1]+mod)%mod;
        }
        sum[i][0]=sum[i-1][0];sum[i][1]=sum[i-1][1];
        sum[i][i&1]=(sum[i][i&1]+f[i])%mod;
    }
    int ans=f[n];
    for(int i=1;i<=L;i+=2)  ans=(ans+1ll*i*f[n-i-1])%mod;
    cout<<ans<<endl;
    return 0;
}