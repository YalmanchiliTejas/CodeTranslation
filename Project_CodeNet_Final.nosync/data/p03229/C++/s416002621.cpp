#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];

    sort(all(a)); // 昇順
    rep(i, n) b[i] = a[i];
    reverse(all(b)); // 降順

    ll ans = 0, now = 0;
    int k = n / 2;
    if (n % 2 == 0) {
        rep(i, k-1) now += 2 * b[i];
        now += b[k-1];
        rep(i, k-1) now -= 2 * a[i];
        now -= a[k-1];
        chmax(ans, now);
    } else {
        rep(i, k-1) now += 2 * b[i];
        now += b[k-1] + b[k];
        rep(i, k) now -= 2 * a[i];
        chmax(ans, now);
        now = 0;
        rep(i, k) now += 2 * b[i];
        rep(i, k-1) now -= 2 * a[i];
        now -= a[k-1] + a[k];
        chmax(ans, now);
    }
    cout << ans << endl;
}
