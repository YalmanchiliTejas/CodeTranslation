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

ll dp1[10010][110], dp2[10010][110];

int main()
{
    FIO;
    string s;
    ll n,d,i,j,k,tp;
    cin>>s>>d;
    n=SZ(s);
    s="$"+s;
    fr(i,n) s[i]-=48;
    for(i=0;i<s[1];i++)
        dp1[1][i%d]++;
    dp2[1][i%d]=1;
//    i=1;
  //  rp(j,d) tr(i,j,dp1[i][j]);
    for(i=2;i<=n;i++)
    {
        for(j=0;j<s[i];j++)
            for(k=0;k<d;k++)
            {
                tp=(k+j)%d;
                dp1[i][tp]=(dp1[i][tp]+dp1[i-1][k]+dp2[i-1][k])%mod;
            }
        for(k=0;k<d;k++)
        {
            tp=(k+j)%d;
            dp2[i][tp]=(dp2[i][tp]+dp2[i-1][k])%mod;
//            tr(i,k,tp,dp2[i][tp]);
        }
        for(;j<10;j++)
            for(k=0;k<d;k++)
            {
                tp=(k+j)%d;
                dp1[i][tp]=(dp1[i][tp]+dp1[i-1][k])%mod; 
            }
//        rp(j,d) tr(i,j,dp1[i][j]);
    }
    cout<<(dp1[n][0]+dp2[n][0]-1+mod)%mod<<endl;
    return 0;
}
