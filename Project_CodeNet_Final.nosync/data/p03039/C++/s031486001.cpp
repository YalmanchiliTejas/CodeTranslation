#include <bits/stdc++.h>
#define mod 1000000007
#define long long long
using namespace std;
int n,m,k;
void readdata()
{
    cin>>n>>m>>k;
}

long power(long x,long y)
{
    if (y==0) return 1;
    long kq=power(x,y/2);
    kq=(kq*kq)%mod;
    if (y%2==1) kq=(kq*x)%mod;
    return kq;
}

long first()
{
    long s=1;
    for (int i=2;i<=k-1;i++)
    {
        s=(s*((n*m-i)%mod))%mod;
    }
    long d=1;
    for (int i=1;i<=k-2;i++)
    {
        d=(d*i)%mod;
    }
    d=power(d,mod-2);
    d=(d*s)%mod;
    return d;
}

long second()
{
    long s=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            long k1=1,k2=1,l1=1,l2=1;
            k1=((k1*(i-1)*(i))%mod*m)%mod;
            l1=((l1*(n-i)*(n-i+1))%mod*m)%mod;
            k2=((k2*(j-1)*(j))%mod*n)%mod;
            l2=((l2*(m-j)*(m-j+1))%mod*n)%mod;
            s=(s+k1+l1+k2+l2)%mod;
        }
    }
    s=(s*power(4,mod-2))%mod;
    return s;
}

void solve()
{
    cout<<((first()*second())%mod);
}

int main()
{
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    readdata();
    solve();
    return 0;
}
