#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll n; cin >> n;
    ll a = 0, b = 0;
    rep(i, n) {
        ll c; cin >> c;
        (a += c) %= MOD;
        (b += c*c%MOD) %= MOD;
    }
    ll ans = a * a % MOD;
    ans -= b;
    if(ans < 0) ans += MOD;
    (ans *= (MOD + 1) / 2) %= MOD;
    cout << ans << endl;;
}
