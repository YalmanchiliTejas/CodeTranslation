#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

ll M;

ll mpow(ll x, ll n, ll m){
    ll ret = 1;
    while(n){
        if(n&1) ret *= x, ret %= m;
        x *= x, x %= m;
        n >>= 1;
    }
    return ret;
}

const int MAX = 3e3;
ll fac[MAX+1], ifac[MAX+1];

void init(){
    fac[0] = 1;
    rep(i, MAX){
        fac[i+1] = fac[i]*(i+1)%M;
    }
    ifac[MAX] = mpow(fac[MAX], M-2, M);
    rep3(i, MAX, 1){
        ifac[i-1] = ifac[i]*i%M;
    }
}

ll perm(int n, int k){
    return fac[n]*ifac[n-k]%M;
}

ll comb(int n, int k){
    return perm(n, k)*ifac[k]%M;
}

int main(){
    int N;
    cin >> N >> M;
    init();
    ll dp[N+1][N+1];
    fill(dp[0], dp[N+1], 0);
    rep(i, N+1){
        dp[i][0] = dp[i][i] = 1;
        rep2(j, 1, i-1){
            dp[i][j] = dp[i-1][j-1]+(j+1)*dp[i-1][j];
            dp[i][j] %= M;
        }
    }
    ll ans = 0;
    rep(i, N+1){
        ll tmp = 0, pw = mpow(2, N-i, M), now = 1;
        rep(j, i+1){
            tmp += dp[i][j]*now, tmp %= M;
            now *= pw, now %= M;
        }
        tmp *= mpow(2, mpow(2, N-i, M-1), M), tmp %= M;
        tmp *= comb(N, i), tmp %= M;
        if(i&1) ans += M-tmp;
        else ans += tmp;
        ans %= M;
    }
    cout << ans << endl;
}