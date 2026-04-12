#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
using namespace std;
typedef pair<int, int> P;
 
int n, a, b, c, d;
int mod = 1e9 + 7;
int dp[1010][1010];

typedef long long ll;
ll mod_pow(ll x,ll n){
	if(n==0) return 1;
	ll res=mod_pow(x*x%mod,n/2);
	if(n&1) res=res*x%mod;
	return res;
}
ll fact[200010];
ll factr[200010];
ll inv[200010];
ll get_nCk(ll n,ll k){
    if(k < 0 || k > n || n < 0) return 0;
    return fact[n]*factr[k]%mod*factr[n - k]%mod;
}
 
int f(int p, int s){
    if(dp[p][s] >= 0) return dp[p][s];  
    if(s == 0) return dp[p][s] = 1;        
    // if(p > b || s < 0 || p > s) return 0;
    if(p > b) return 0;
      
    int res = 0;
    int t = 1;
    rep(i, 1, d + 1){
        if(s - p * i < 0) break;
        t = t * get_nCk(s - p * (i - 1), p) % mod * inv[i] % mod;
        if(c <= i && i <= d){
            res += f(p + 1, s - p * i) * t % mod;
        }
    }
    // rep(i, c, d + 1){
    //     if(s - p * i < 0) break;
    // }
    // cout << p << " " << s <<" " <<  res << endl;
    
    res += f(p + 1, s);
    
    return dp[p][s] = res % mod;
}
 
signed main(){
    cin >> n >> a >> b >> c >> d;
    rep(i, 0, 1010){
        rep(j, 0, 1010){
            dp[i][j] = -1;
        }
    }
    fact[0] = 1;
    factr[0] = 1;
    inv[1] = 1;
	for(int i=1;i<1010;i++) fact[i]=fact[i-1]*i%mod;
    for(int i = 1; i < 1010; i++) factr[i] = mod_pow(fact[i], mod - 2);
    for(int i = 2; i < 1010; i++) inv[i] = mod_pow(i, mod - 2);
    cout << f(a, n) << endl;
    // rep(i, a, b + 1){
    //     rep(j, 0, n + 1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}