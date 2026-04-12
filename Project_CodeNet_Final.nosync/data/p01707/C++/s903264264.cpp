#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 1000000007;
ll inv[5000];
ll beki(ll a, ll b) {
    a %= mod;
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}

ll combination(ll a, ll b) {
    ll ret = 1;
    for(ll i = 1; i <= b; i++) {
        ret *= (a + 1 - i) % mod;
        ret %= mod;
        ret *= inv[i];
        ret %= mod;
    }
    return ret;
}

ll N, D, X;

void solve() {
    ll ans = 0;
    for(ll ng = 0; ng <= D; ng++) {
        ll rest = N - X * ng;
        if(rest < 0) break;
        ll tmp = combination(D, ng);
        tmp *= combination(rest + D - 1, rest);
        tmp %= mod;
        if(ng & 1) ans -= tmp;
        else ans += tmp;
        //cerr << ng << " " << tmp << endl;
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 4000; i++) {
        inv[i] = beki(i, mod - 2);
    }
    while(cin >> N >> D >> X) {
        if(N == 0) break;
        solve();
    }
    return 0;
}
