//No matter how imaginary the dreams are, i over i is always real!
//#include <boost/multiprecision/cpp_int.hpp> 
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
typedef long long int ll;
typedef double db;
// __int128 s128;
// __uint128_t u128;
typedef unsigned long long u64;
#define int long long int
#define P 1000000007
#define Q 1000000006
#define sz(a) (ll)a.size()
#define lt(a) (ll)a.length()
#define pll pair<ll,ll>
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define bac(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define teevra_gati ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define N 3000
#define PI 3.14159265359
#define inf LLONG_MAX
//using namespace boost::multiprecision; 
using namespace __gnu_pbds;
using namespace std;

void solve(){
    ll n,sum=0;
    cin>>n;
    vl a(n+1);
    ll dp[n+1][n+1] = {};
    f(i,1,n+1) cin>>a[i], dp[i][i]=a[i], sum += a[i];
    f(d,1,n){
        f(i,1,n-d+1){
            ll j = i+d;
            ll p1=0, p2=0, p3=0, p4=0;

            if(i+2<=j) p1 = dp[i+2][j];
            if(j-1>=i+1) p2 = dp[i+1][j-1];
            if(j-2>=i) p3 = dp[i][j-2];

            ll left = a[i] + min(p1, p2);
            ll right = a[j] + min(p3, p2);

            dp[i][j] = max(left,right);
        }
    }
    cout<<2*dp[1][n] - sum;
}
signed main() {
    teevra_gati
        
    solve();

    return 0;
}