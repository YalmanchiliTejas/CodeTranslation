#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define BUGAVOID(x) x
#define rep(...) BUGAVOID(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define mp make_pair
#define write(x) cout<<(x)<<"\n"
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vll; template<class T>using vv = vector<vector<T>>;
template<class T>vv<T> vvec(size_t n, size_t m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T>bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 28, MOD = 1e9 + 7; constexpr ll LINF = 1ll << 60; constexpr double EPS = 1e-6;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); }; }aaaa;

int main() {
    ll N, X;
    cin >> N >> X;

    vll n_layer(51), n_patty(51);
    n_layer[0] = 1;
    n_patty[0] = 1;
    rep(i, 50) {
        n_layer[i + 1] = 2 * n_layer[i] + 3;
        n_patty[i + 1] = 2 * n_patty[i] + 1;
    }

    ll ans = 0;
    ll n = N;
    ll x = X;
    for (; n;) {
        if (x == 0) {
            break;
        }
        else if (x == n_layer[n]) {
            ans += n_patty[n];
            break;
        }
        else if (x <= n_layer[n] / 2) {
            x--;
            n--;
        }
        else if (x == n_layer[n] / 2 + 1) {
            ans += n_patty[n - 1] + 1;
            break;
        }
        else {
            ans += n_patty[n - 1] + 1;
            x -= n_layer[n] / 2 + 1;
            n--;
        }
    }
    if (n == 0 && x == 1) ans++;

    write(ans);
}