#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(x) (int)x.size()
typedef long double f80;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

ll pwr(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
const int N = 4e5 + 5;

int fact[N], ifact[N];

ll x[N], y[N];

signed main()
{
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    fr(i, 1, N - 1) {
        fact[i] = ((ll)i * fact[i - 1]) % mod;
    }
    ifact[N - 1] = pwr(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--) {
        ifact[i] = ((ll)ifact[i + 1] * (i + 1)) % mod;
    }
    assert(ifact[0] == 1);
    int n, m, k;
    cin >> n >> m >> k;
    int cc = 0;
    fr(i, 1, n) {
        fr(j, 1, m) {
            ++cc;
            x[cc] = i;
            y[cc] = j;
        }
    }
    n *= m;
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    ll val = ((ll)fact[n - 2] * ifact[k - 2]) % mod;
    val = (val * ifact[n - k]) % mod;
    ll ans = 0;
    fr(i ,1, n) {
        // cout << x[i] << " " << y[i] << endl;
        ll val1 = ((ll)(i - 1) * x[i]) % mod - x[i - 1] + mod;
        ll val2 = ((ll)(i - 1) * y[i]) % mod - y[i - 1] + mod;
        val1 %= mod;
        val2 %= mod;
        val1 = (val1 * val) % mod;
        val2 = (val2 * val) % mod;
        ans = (ans + val1) % mod;
        ans = (ans + val2) % mod;
        x[i] += x[i - 1];
        x[i] %= mod;
        y[i] += y[i - 1];
        y[i] %= mod;
    }
    cout << ans;
    return 0;
}