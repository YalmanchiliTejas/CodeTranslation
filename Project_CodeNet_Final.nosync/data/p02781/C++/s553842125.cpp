#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
using intmap = map<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
inline bool bit (ll b, ll i) { return b & (1 << i); }
inline ll ceiv (ll a, ll b) { return (a + b - 1) / b; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define debug(x) cerr << #x << ": " << x << '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

int binom_max = 5e5+1;
vector<int> fact(binom_max), inv_fact(binom_max), inv(binom_max);

void modbinom_init() {
    fact[0] = fact[1] = 1;
    inv_fact[0] = inv_fact[1] = 1;
    inv[1] = 1;
    for(int i=2; i<binom_max; i++){
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        inv_fact[i] = inv_fact[i-1] * inv[i] % MOD;
    }
}

int comb(int n, int k){
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return fact[n] * (inv_fact[k] * inv_fact[n-k] % MOD) % MOD;
}

int perm(int n, int k){
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return (fact[n] * inv_fact[n-k]) % MOD;
}

int modpow(int a, int n, int m = MOD){
    ll ret = 1;
    while(n > 0){
        if(n&1) ret = (ret*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ret % m;
}

signed main(){
    modbinom_init();
    string n; int k;
    cin >> n >> k;
    
    const int LEN = n.length();
    int nzl = k;
    int ans = 0;
    
    rep(i, LEN){
        int top = n[i] - '0';
        
        if(top != 0){
            //__0######
            ans += mod(modpow(9,nzl) * comb(LEN-1-i, nzl));
            //__[1-9]######
            ans += mod(max(0LL, top-1) * modpow(9,nzl-1) * comb(LEN-1-i, nzl-1));
            nzl--;
        }
        
        ans %= MOD;
    }
    
    if(nzl == 0) ans = mod(1 + ans);
    
    cout << ans << endl;
}