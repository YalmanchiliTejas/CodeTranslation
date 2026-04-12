// https://atcoder.jp/contests/abcXXX/tasks/abcXXX_x

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

static const ll INF = 1001001001;
static const ll LLINF = 1001001001001001001;
static const ll MOD = (ll)1e9 + 7;
static const double EPS = 1e-9;

#define REP(i, n) for(ll i = 0; i < static_cast<ll>(n); ++i)
#define RANGE(i, m, n) for(ll i = (m); i <= static_cast<ll>(n); ++i)
#define RRANGE(i, m, n) for(ll i = static_cast<ll>(m); i >= static_cast<ll>(n); --i)
#define POSITIVE(x) (x)=((x) < 0) ? 0 : (x)

ll power(ll x, ll y) {
    ll ret = 1;
    while(y-- > 0) ret *= x;
    return ret;
}

ll gcd(ll a, ll b) {
    assert(a >= 0);
    assert(b >= 0);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1; y = 0;
    assert(a >= 0);
    assert(b >= 0);
    if (b == 0) return a;
    ll X, Y;
    auto d = extgcd(b, a % b, X, Y);
    x = Y;
    y = X - (a / b) * Y;
    return d;
}

int run(istream& in, ostream& out) {
    ll N;
    in >> N;
    vector<ll> v(N);
    ll total = 0;
    REP(i, N) {
        in >> v[i];
        total += v[i];
        total %= MOD;
    }
    ll ans = 0;
    REP(i, N-1) {
        total -= v[i];
        total += MOD;
        total %= MOD;
        ans += (total * v[i] % MOD);
        ans %= MOD;
    }
    out << ans << endl;
    return 0;
}

int main() {
    return run(cin, cout);
}
