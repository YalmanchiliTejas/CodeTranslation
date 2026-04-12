#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1000000000000000
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a)%mod;  a = (a * a)%mod;  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const ll N = 10003;
ll n,d;
string k;
ll dp[N][2][103];
ll solve(ll i,bool small,ll m)
{
    if(dp[i][small][m] != -1) return dp[i][small][m];
    
    if(i == n)
        return dp[i][small][m] = (m == 0 ? 1 : 0);
    
    ll res = 0;
    ll limit = (small ? 9 : k[i] - '0');
    for(ll use = 0;use <= limit;use += 1)
        res = (res + solve(i + 1,(use < k[i] - '0' ? 1 : small),(m + use) % d)) % mod;
    
    return dp[i][small][m] = res;
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    n = k.length();
    cout<<(solve(0,0,0) - 1 + mod) % mod;
    return 0;
}