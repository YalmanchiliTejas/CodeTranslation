#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const ll INF = numeric_limits<ll>::max();
const int mod = 1000000007;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main()
{
    int n; cin >> n;
    VI a(n); rep(i, n) cin >> a[i];
    ll aa = 0;
    rep(i, n) {
        aa += a[i]*a[i];
        aa %= mod;
    }
    ll suma = 0;
    rep(i, n) {
        suma += a[i];
        suma %= mod;
    }
    ll ans = suma*suma - aa;
    ans %= mod;
    ans *= modinv(2, mod);
    ans %= mod;
    cout << ans << endl;
    return 0;
}