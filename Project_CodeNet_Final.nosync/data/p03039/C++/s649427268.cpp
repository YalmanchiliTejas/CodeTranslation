#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;

ll kai[200001];
ll mokai[200001];

ll mod_pow (ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y&1) ret = ret*x%MOD;
        x = x*x%MOD;
        y /= 2;
    }
    return ret;
}

void init (int _n) {
    kai[0] = 1;
    for (int i = 1; i <= _n; i++) kai[i] = kai[i-1]*i%MOD;
    for (int i = 0; i <= _n; i++) mokai[i] = mod_pow(kai[i],MOD-2);
}

ll conb (ll x, ll y) {
    ll z = x-y;
    if (z < 0) return 0;
    ll ret = kai[x]*mokai[y]%MOD;
    ret = ret*mokai[z]%MOD;
    return ret;
}

ll n, m, k;
ll ans = 0;

int main() {
    cin >> n >> m >> k;
    init(200000);
    {
        ll tmp = conb(n*m-2, k-2);
        tmp = tmp * m % MOD; tmp = tmp * m % MOD;
        ll sum = 0;
        for (ll d = 1; d < n; d++) {
            sum = (sum + (n-d) * d) % MOD;
        } 
        ans = tmp * sum % MOD;
    }
    {
        ll tmp = conb(n*m-2, k-2);
        tmp = tmp * n % MOD; tmp = tmp * n % MOD;
        ll sum = 0;
        for (ll d = 1; d < m; d++) {
            sum = (sum + (m-d) * d) % MOD;
        } 
        ans = (ans + tmp * sum) % MOD;
    }
    cout << ans << endl;
}
