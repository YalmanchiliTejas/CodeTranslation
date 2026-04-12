// https://atcoder.jp/contests/abcXXX/tasks/abcXXX_x

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

static const ll INF = 1001001001;
static const ll LLINF = 1001001001001001001;

#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define RANGE(i, m, n) for(ll i = (m); i <= (n); ++i)
#define RRANGE(i, m, n) for(ll i = (m); i >= (n); --i)
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
    string S;

    in >> S;
    ll ans = 0;
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());


    out << ((S.size() == 1) ? "No": "Yes") << endl;
    return 0;
}

int run2(istream& in, ostream& out) {
    ll N, M, R;
    in >> N >> M >> R;
    vector<ll> r{};
    REP(i, R) {
        ll x;
        in >> x;
        r.emplace_back(x);
    }
    vector<tuple<ll,ll,ll>> v{};
    REP(i, M) {
        ll a,b,c;
        in >> a >> b >> c;
        v.emplace_back(make_tuple(a,b,c));
    }

    ll ans = 0;

    // solution here

    out << ans << endl;
    return 0;
}

int main() {
    return run(cin, cout);
}
