#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define IOS {ios :: sync_with_stdio(false); cin.tie(0);cout.tie(0); }
#define F first
#define S second
#define pb push_back
typedef long double ld;
#define deci(n) cout << fixed << setprecision(n);
typedef long long ll;

#define mem0(x)  memset(x,0,sizeof(x));
#define mem1(x)  memset(x,1,sizeof(x));
#define memm1(x) memset(x,-1,sizeof(x));
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define bits(x) __builtin_popcount(x)
#define fori(n)  for (ll i = 0; i < n; i++)
#define fori2(n) for(ll i=1;i<=n;i++)
#define forj(n)  for (ll j = 0; j < n; j++)
#define forj2(n) for(ll j=1;j<=n;j++)
#define fork(n)  for (ll k = 0; k < n; k++)
#define fork2(n) for(ll k=1;k<=n;k++)
#define vll vector <ll>
#define mll map <ll, ll>
#define vpll vector <pll>
const ll md = 1e9 + 7;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))
// const ll N = 100005;
// ll fac[N] = {1};
// #define calfac for(ll i=1  ;i<N;i++) fac[i] = (fac[i-1]*i)%md;
// ll C[N+1][M+1]; 
// void  ncr(){
//     ll n = N,k = M; 
//     for (ll i = 0; i <= n; i++) { 
//         for (ll j = 0; j <= min(i, k); j++) { 
//             if (j == 0 || j == i)  C[i][j] = 1; 
//             else C[i][j] = C[i - 1][j - 1] +  C[i - 1][j]; 
//         } 
//     } 
// } 


#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}
ll modInv(ll a)
{
    return pow(a,md-2);
}
 
// ll nCr(ll n,ll r)
// {
//     return (fac[n]*modInv((fac[r]*fac[n-r])%md))%md;
// }

 
ll po(ll x,ll n){
    if(n==0) return 1;
    if(n%2==1) return (x*po(x,n-1));
    else {
        ll k=po(x,n/2);
        return (k*k);
    }
}
 
ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
}
 
const ll N = 3004;
ll dp[N][N],a[N],sum[N];


int32_t main(){
    IOS;
    ll i,j,k,n,m,p,l;
    cin >> n;
    fori2(n) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(l = 1 ; l <= n ;l++){
        for(i = 1 ; i <= n - l + 1 ; i++){
            j = i + l - 1;
            if(l==1) dp[i][i] = a[i];
            else if(l==2) dp[i][j] = max(a[i],a[i+1]);
            else {
                ll v1 = dp[i+1][j];
                ll v2 = dp[i][j-1];
                dp[i][j] = sum[j] - sum[i-1] - min(v1,v2);
                // if(v1 < v2){
                //     dp[i][j] = a[i];
                //     if(dp[i+1][j-1]>=dp[i+2][j]){
                //         dp[i][j] += dp[i+1][j-1];
                //     }
                //     else {
                //         dp[i][j] += dp[i+2][j];
                //     }
                // }
                // else {
                //     dp[i][j] = a[j];
                //     if(dp[i+1][j-1]>=dp[i][j-2]){
                //         dp[i][j] += dp[i+1][j-1];
                //     }
                //     else {
                //         dp[i][j] += dp[i][j-2];
                //     }
                // }
            }
        }
    }
    cout << 2*dp[1][n] - sum[n] <<"\n";

} 