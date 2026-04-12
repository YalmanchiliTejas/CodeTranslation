// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <complex>
#define rep(i, x) for (int i = 0; i < (x); ++i)
#define rng(i, x, y) for (int i = (x); i < (y); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}

// Main Code
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    sort(all(a));
    reverse(all(a));
    ll ans1 = 0, ans2 = 0;
    if (n & 1) {
        rng(i, 0, (n - 1) / 2) ans1 += 2 * a[i];
        rng(i, (n - 1) / 2, (n + 3) / 2) ans1 -= a[i];
        rng(i, (n + 3) / 2, n) ans1 -= 2 * a[i];
    } else {
        rng(i, 0, n / 2 - 1) ans1 += 2 * a[i];
        rng(i, n / 2 - 1, n / 2) ans1 += a[i];
        rng(i, n / 2, n / 2 + 1) ans1 -= a[i];
        rng(i, n / 2 + 1 , n) ans1 -= 2 * a[i];
    }
    if (n & 1) {
        rng(i, 0, (n - 3) / 2) ans2 += a[i] * 2;
        rng(i, (n - 3) / 2, (n + 1) / 2) ans2 += a[i];
        rng(i, (n + 1) / 2, n) ans2 -= a[i] * 2;
    }
    cout << max(ans1, ans2) << "\n";
    return;
}
