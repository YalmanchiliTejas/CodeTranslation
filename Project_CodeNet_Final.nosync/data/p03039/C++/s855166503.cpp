#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define F first
#define re return
#define S second
#define ll long long
#define f(i) return cout<<i<<"\n",0;
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define lp(i,a,b) for (int i=(a);i<=(int)(b);++i)
#define lp2(i,a,b) for (int i=(a);i>=(b);--i)
#define clr(c,x) memset(c,x,sizeof(c))
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
const int N=2e5+5,mod=(int)1e9+7;
vl x,y;
inline ll Manhttan(vl &v)
{
    ll res=0,sum=0;
    lp(i,0,v.size()-1)
    {
        res+=(v[i]*i-sum);
        sum+=v[i];
    }
    return (res%mod);
}
inline ll fp(int base,int po)
{
    if (!po) return 1;
    ll ret=fp(base,po/2);
    ret%=mod;
    ret*=ret;
    ret%=mod;
    if (po&1)
    {
        ret*=base;
        ret%=mod;
    }
    return ret;
}
ll fact[N]= {};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    fact[0]=1;
    lp(i,1,n*m)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    lp(i,1,n)
    {
        lp(j,1,m)
        {
            x.pb(i);
            y.pb(j);
        }
    }
    sort(all(x));
    sort(all(y));
    ll res=Manhttan(x)+Manhttan(y);
    res%=mod;
    ll z=fact[k-2]*fact[n*m-k];
    z%=mod;
    ll res2=fp(z,mod-2);
    res2*=fact[n*m-2];
    res2%=mod;
    res*=res2;
    res%=mod;
    cout<<res<<"\n";
    return 0;
}