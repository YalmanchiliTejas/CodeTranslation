// template {{{
#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define sz(c) (static_cast<int>(c.size()))
#define endl "\n"

using ld = long double;
using ll = long long;

inline ll addm(ll __a, ll __b, ll __m);
inline ll subm(ll __a, ll __b, ll __m);
inline ll mulm(ll __a, ll __b, ll __m);
ll powm(ll __a, ll __b, ll __m);
ll inv(ll __x, ll __m);
// }}}

const ll INFL = numeric_limits<ll>::max() / 2;
const ll INF = numeric_limits<int>::max() / 2;
const ll MOD = 1e9+7;

const int N = 10500;
const int D = 105;

ll mem[D][N];
int d;

ll dp(int s, int l)
{
    if (l == 0) return (s == 0);
    ll &ret = mem[s][l];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= 9; i++) {
        ret = (ret + dp((s + i) % d, l-1)) % MOD;
    }
    return ret;
}

void solve()
{
    memset(mem, -1, sizeof(mem));
    string k;
    cin >> k >> d;
    int n = sz(k);
    ll ans = 0;
    int cur = 0;
    for (int l = 0; l < n; l++) {
        for (int g = 0; g < k[l]-'0'; g++) {
            int sum = cur + g;
            ans = (ans + dp(sum % d, n-l-1)) % MOD;
        }
        cur += k[l]-'0';
    }
    if (cur % d != 0) ans = (ans+MOD-1)%MOD;
    cout << ans << endl;
}

// main {{{
int main()
{
    cin.sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}

inline ll addm(ll __a, ll __b, ll __m = MOD) {
    return ((__a+__b)%__m);
}
inline ll subm(ll __a, ll __b, ll __m = MOD) {
    return (((__a-__b)%__m+__m)%__m);
}
inline ll mulm(ll __a, ll __b, ll __m = MOD) {
    return ((__a*__b)%__m);
}
ll powm(ll __a, ll __b, ll __m = MOD) {
    ll ret = (!__b) ? 1 : powm(__a, __b/2, __m);
    return (!__b) ? 1 : mulm(mulm(ret, ret, __m), (__b%2) ? __a : 1, __m);
}
ll inv(ll __x, ll __m = MOD) {
    return powm(__x, __m-2, __m);
}
// }}}
