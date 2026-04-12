#include <bits/stdc++.h>

using namespace std;
const long long mod=1000000007;

void modify(long long &a)
{
    if(a>=mod) a%=mod;
}

long long fastpow(long long b,long long e)
{
    long long res=1;
    while(e)
    {
        if(e&1) res*=b;
        modify(res);
        b*=b;
        modify(b);
        e/=2;
    }
    return res;
}

long long choose(long long n,long long k)
{
    long long res=1;
    for(long long i=n-k+1;i<=n;i++)
    {
        res*=i;
        modify(res);
    }
    for(long long i=1;i<=k;i++)
    {
        res*=fastpow(i,mod-2);
        modify(res);
    }
    return res;
}

int main()
{
    long long n,m,k;
    cin >> n >> m >> k;
    long long c=choose(n*m-2,k-2);
    long long res=0;
    for(long long i=1;i<m;i++)
    {
        long long now=c;
        now*=n;
        modify(now);
        now*=n;
        modify(now);
        now*=i;
        modify(now);
        now*=(m-i);
        modify(now);
        res+=now;
        modify(res);
    }
    for(long long i=1;i<n;i++)
    {
        long long now=c;
        now*=m;
        modify(now);
        now*=m;
        modify(now);
        now*=i;
        modify(now);
        now*=(n-i);
        modify(now);
        res+=now;
        modify(res);
    }
    cout << res << endl;
    return 0;
}
