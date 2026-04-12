

// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep3(i, l, r) for (ll i = (ll)(l); i < (ll)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    
    vector<ll> vec;
    vec.push_back(x);
    vector<ll> idx(m, -1);
    idx[x] = 0;
    ll ans = x;
    rep(i, 1, n) {
        ll y = vec[i - 1] * vec[i - 1] % m;
        if (ll a = idx[y]; a != -1) {
            ll nokori = n - i;
            ll shuki = i - a;
            ll shuki_sum = 0;
            rep(j, shuki) shuki_sum += vec[a + j];
            ans += nokori / shuki * shuki_sum;
            nokori %= shuki;
            rep(j, nokori) ans += vec[a + j];
            cout << ans << "\n";
            return 0;
        }
        vec.push_back(y);
        idx[y] = i;
        ans += y;
    }
    
    cout << ans << "\n";
}
