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
    if(k < 0 || k > n) return 0;
    return fact[n]*factr[k]%mod*factr[n - k]%mod;
}

int f(int p, int s){
    // if(s == 0) return 1;    
    // if(dp[p][s] != -1) return dp[p][s];  
    // if(p > b || s < 0) return 0;
      
    int& res = dp[p][s];
    if(res >= 0) return res;
    res = 0;
    if(s == 0){
        res = 1;
    }else{
        if(p > b) return 0;
        res += f(p + 1, s);
        int v = 1;
        for(int i = 1; i <= d && p <= s; i++){
            (v *= get_nCk(s, p) * inv[i] % mod) %= mod;
            s -= p;
            if(c <= i && i <= d){
                res += v * f(p + 1, s) % mod;
                // cout << p << " " << s << " " << i << " " << v << " " << res << endl;
            }
        }
    }
    res %= mod;
    return res;
 
}
//         }
//     }
//     int tmp[1010];
//     tmp[0] = 1;
//     rep(i, 1, d + 1){
//         if(s - p * (i - 1) < 0) break;
//         tmp[i] = tmp[i - 1] * get_nCk(s - p * (i - 1), p) % mod;
//         tmp[i] = tmp[i] * mod_pow(fact[i], mod - 2) % mod;
//     }
//     rep(i, c, d + 1){
//         if(s - p * i < 0) break;
//         (res += f(p + 1, s - p * i) * tmp[i]) %= mod;
//     }
//     // cout << p << " " << s <<" " <<  res << endl;
    
//     res += f(p + 1, s);
    
//     return dp[p][s] = res % mod;
// }

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