// Author : Chi
// created :
// Sawal : Practice

//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <pair<int,int>, null_type, greater<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//macros
#define ll 		    long long
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb(x)       push_back(x)
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define TEST1       solve();
#define mod         1000000007
#define aLL(x)      x.begin(),x.end()
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define db(...)     __f(#__VA_ARGS__, __VA_ARGS__)                      //for debugging
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
//LOVE ALGO
int dp[10010][101][2];
int n;
string k;
ll solve(int D,int p,int sum,int tight){
    int &mem=dp[p][sum][tight];
    int ub=(tight ? k[p]-'0' : 9);
    if(p == n-1){
        ll ans=0;
        for(int i=0;i <= ub;i++)
            if(sum == i%D)
                ans++;
        return ans;
    }
    if(mem!=-1)
        return mem%mod;
    ll ans=0;
    for(int i=0;i<=ub;i++)
        ans=(ans+solve(D,p+1,(D+sum-i%D)%D,(tight && i==ub))%mod)%mod;
    return mem=ans%mod;
}
void solve(){
    int d;
    cin>>k>>d;
    n=k.length();
    memset(dp,-1,sizeof dp);
    cout<<(mod+solve(d,0,0,1)-1)%mod;
    }
// Driver Code
int main(){
    CHI
    TEST1
    return 0;
}
