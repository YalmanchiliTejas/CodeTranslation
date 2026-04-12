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

using namespace std;

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

void solve() {
    ll n, x, m;
    cin >> n >> x >> m;
    vb seen(m, false);
    vll hist;
    ll now = x;
    while(true) {
        if(seen[now]) break;
        seen[now] = true;
        hist.push_back(now);
        now = (now * now) % m;
    }
    ll last_idx = 0;
    rep(i, hist.size()) {
        if(hist[i] == now) {
            last_idx = i;
            break;
        }
    }
    ll loop = hist.size() - last_idx;
    ll sum = 0;
    for(int i = last_idx; i < hist.size(); ++i) sum += hist[i];
    ll ans = 0;
    for(int i = 0; i < min(n, last_idx); ++i) ans += hist[i];
    if(n <= last_idx) {
        cout << ans << endl;
        return;
    }
    n -= last_idx;
    ans += sum * (n / loop);
    ll remain = n % loop;
    rep(i, remain) ans += hist[i + last_idx];
    cout << ans << endl;
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}