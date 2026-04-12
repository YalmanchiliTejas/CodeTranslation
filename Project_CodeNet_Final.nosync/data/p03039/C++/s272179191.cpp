#include <iostream>
#include <cstdio>
using namespace std;
const int mod=1000000007;
long long a,b,c;
void factorial(int x, int y,int z)
{
    long long s=1,t=max(x,max(y,z));
    for(int i=0;i<=t;++i)
    {
        if(i>0) s=s*i%mod;
        if(i==x)  a=s;
        if(i==y)  b=s;
        if(i==z)  c=s;
    }
    return;
}
long long pw(long long x, int p=mod-2)
{
    long long r=1;
    for(;p;p>>=1,x=x*x%mod)  if(p&1)  r=r*x%mod;
    return r;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    factorial(k-2,m*n-2,m*n-k);
    a=pw(a,mod-2);
    c=pw(c,mod-2);
    long long v=(a*b)%mod*c%mod,res=0;
    for(int i=1;i<n;++i)   res=(res+1ll*i*(n-i)*m*m*v)%mod;
    for(int i=1;i<m;++i)   res=(res+1ll*i*(m-i)*n*n*v)%mod;
    printf("%lld",(res+mod)%mod);
    return 0;
}
