#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define TRACE
#ifdef TRACE
#define tr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define tr(...)
#endif

#define ll long long
#define ld long double 
#define endl "\n"
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (ll)(a.size())
#define all(a) a.begin(), a.end() 
#define fr(i,n) for(i=1;i<=n;i++)
#define rp(i,n) for(i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
typedef pair<ll, ll> ii;
typedef vector<ll> vl;
const ll N = 200010;
ll mod=1e9+7;

ll ffmod(ll x, ll y, ll mod)
{
    ll rt=1;
    while(y)
    {
        if(y&1ll) rt=(rt*x)%mod;
        x=(x*x)%mod, y/=2ll;
    }
    return rt;
}

ll dp[3010][3010][3], a[3010];

int main()
{
    FIO;
    ll n,i,j,tp;
    cin>>n;
    fr(i,n) cin>>a[i];
    fr(i,n) dp[i][i][1]=a[i], dp[i][i][2]=-a[i];
    for(i=2;i<=n;i++)
        for(j=1;j+i-1<=n;j++)
        {
            tp=j+i-1;
            dp[j][tp][1]=max(a[j]+dp[j+1][tp][2], a[tp]+dp[j][tp-1][2]);
            dp[j][tp][2]=min(-a[j]+dp[j+1][tp][1], -a[tp]+dp[j][tp-1][1]);
        }
    cout<<dp[1][n][1]<<endl;
    return 0;
}
