// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;

ll MOD = 10000;

// ModInt begin

ll mod_pow(ll x, ll n, ll mod=MOD) {
    ll ret = 1;
    x %= MOD;
    for(; n; n>>=1) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
    }
    return ret;
}

struct ModInt {
    ll v;
    ModInt(ll a = 0) : v(((a%MOD) + MOD) % MOD) {}
    ModInt  operator+ ( const ModInt& b ) const {return (v + b.v) % MOD;}
    ModInt  operator- ( const ModInt& b ) const {return (v - b.v + MOD) % MOD;}
    ModInt  operator* ( const ModInt& b ) const {return (v * b.v) % MOD;}
    ModInt  operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, MOD-2)) % MOD;}
};

bool    operator==(ModInt  a, ModInt b) {return a.v == b.v;}
ModInt& operator+=(ModInt& a, ModInt b) {return a = a + b;}
ModInt& operator-=(ModInt& a, ModInt b) {return a = a - b;}
ModInt& operator*=(ModInt& a, ModInt b) {return a = a * b;}
ModInt& operator/=(ModInt& a, ModInt b) {return a = a / b;}
ostream& operator<<(ostream& out, ModInt  a) {return out << a.v;}
istream& operator>>(istream& in,  ModInt& a) {
    ll v; in >> v;
    a = ModInt(v);
    return in;
}

// ModInt end

ModInt dp[3010][3010], ways[3010];
ModInt fact[3010], inv[3010];

ModInt comb(int N, int K) {
    ModInt ans = fact[N] * inv[N-K] * inv[K];
    return ans;
}
 
signed main() {
    int N; cin >> N >> MOD;

    fact[0] = ModInt(1);
    for(int i=1; i<=N; i++) {
        fact[i] = fact[i-1] * i;
    }
    inv[N] = ModInt(mod_pow(fact[N].v, MOD-2));
    for(int i=N-1; i>=0; i--) {
        inv[i] = inv[i+1] * (i+1);
    }

    for(int i=0; i<=N; i++) {
        dp[i][0] = 1;
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * (j+1);
        }
    }

    for(int i=0; i<=N; i++) {
        for(int j=0; j<=i; j++) {
            ways[i] += dp[i][j] * mod_pow(2, (N-i)*j);
        }
        ways[i] *= mod_pow(2, mod_pow(2, N-i, MOD-1));
    }

    ModInt ans = 0;
    for(int i=0; i<=N; i++) {
        ModInt val = comb(N, i) * ways[i];
        if(i % 2 == 1) ans -= val;
        if(i % 2 == 0) ans += val;
    }
    cout << ans << endl;
    return 0;
}