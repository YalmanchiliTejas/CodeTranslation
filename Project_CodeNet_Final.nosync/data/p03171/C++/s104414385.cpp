#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int n;
vector<ll> a;
auto memo = make_vec<ll>(3030, 3030);
ll dp(int l, int r) {
    if (memo[l][r] != -1) return memo[l][r];
    int len = r - l + 1;
    if (len == 0) return 0;
    ll ret;
    if (len % 2 == n % 2) {
        if (len == 1)
            ret = a[l];
        else
            ret = max(dp(l + 1, r) + a[l], dp(l, r - 1) + a[r]);
    } else {
        if (len == 1)
            ret = -a[l];
        else
            ret = min(dp(l + 1, r) - a[l], dp(l, r - 1) - a[r]);
    }
    return memo[l][r] = ret;
}
int main() {
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, 3030) rep(j, 3030) memo[i][j] = -1;
    cout << dp(0, n - 1) << endl;
}