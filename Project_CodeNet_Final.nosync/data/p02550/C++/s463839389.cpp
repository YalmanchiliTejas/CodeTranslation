#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
const int N = 100005;

ll val[N];
ll idx[N];
ll pre[N];

int _runtimeTerror_()
{
    ll n,x,m;
    cin>>n>>x>>m;
    val[0] = 1;
    val[1] = x;
    for(int i=2;i<=m+1;++i)
        val[i] = val[i-1]*val[i-1]%m;
    pre[1] = val[1];
    for(int i=2;i<=m+1;++i)
        pre[i] = pre[i-1] +val[i];
    if(n<=m+1)
    {
        ll ans = 0;
        for(int i=1;i<=n;++i)
        {
            ans += val[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    ll sum =0,period = 0;
    ll ans = 0;
    for(int i=1;i<=m+1;++i)
    {
        if(idx[val[i]]!=0)
        {
            ll j = idx[val[i]];
            sum = pre[i]-pre[j];
            period = i-j;
            ans += pre[j-1];
            ll xx = n;
            xx -= j-1;
            ans += (xx/period)*sum;
            xx %= period;
            int cur = j;
            while(xx--)
                ans += val[j++];
            break;
        }
        idx[val[i]] = i;
    }
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}