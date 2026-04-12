#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
#include <deque>
#include <complex>
#include <bitset>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

typedef vector<bool> vb;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rreps(i, n) for (ll i = (n); i >= 1; i--)
#define all(v) (v).begin(), (v).end()

template <class T> void chmin(T& a, T b) { a = min(a, b);}
template <class T> void chmax(T& a, T b) { a = max(a, b);}

constexpr int INF = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-12;
ld PI = acos(-1.0);

ll op(ll a, ll b) { return max(a, b); }
ll e() { return -1ll; }
ll target;
bool f(ll a) { return a < target; }

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    rep(i, n) cin >> a[i];
    segtree<ll, op, e> seg(a);
    while(q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) seg.set(x-1, y);
        else if(t == 2) cout << seg.prod(x-1, y) << endl;
        else if(t == 3) {
            target = y;
            cout << seg.max_right<f>(x-1) + 1 << endl;
        }
    }
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}