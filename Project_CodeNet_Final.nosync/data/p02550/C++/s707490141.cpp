#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
 lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x =((x%MOD)+(y%MOD))%MOD;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return ((x%MOD)*(y%MOD))% MOD;
}

lld binpow(lld x, lld y)
{
    lld z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

lld inv(lld x)
{
    return binpow(x, MOD - 2);
}

lld divide(lld x, lld y)
{
    return mul(x, inv(y));
}

// Combinations

/*
lld fact[N];

void precalc()
{
    fact[0] = 1;
    for(lld i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

lld C(lld n, lld k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;

    while(t--)
    {
        lld n,x,m;
        cin>>n>>x>>m;
        lld ans=x;
        MOD=m;
        lld a=x;
        map<lld,lld>ar;
        map<lld,lld>br;
        ar[x]=1;
        br[x]=x;
        for(i=2;i<=min(3000000ll,n);i++)
            {
                a=mul(a,a);
                if(a==0)
                    {
                        cout<<ans<<endl;
                        return 0;
                    }
                else
                if(ar[a]!=0)
                    {   //cout<<a<<" "<<ar[a]<<" "<<br[a]<<" "<<i<<endl;
                        ans+=a;
                        lld sum=ans-br[a];
                        lld turn=i-ar[a];
                        lld left=n-i;
                        ans+=(left/turn)*sum;
                        left=left%turn;
                        for(i=0;i<left;i++)
                        {
                            a=mul(a,a);
                            ans+=a;

                        }
                        cout<<ans<<endl;
                        return 0;

                    }
                else
                    ans+=a,ar[a]=i,br[a]=ans;
            }
        cout<<ans<<endl;
    }
}



