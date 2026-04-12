#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 10000007
#define MOD 998244353
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2;
vector<ll> g[300500], f;

ll fac[MAXN], invfac[MAXN];

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

ll C(ll n, ll m) {
    if (n < m) {
        return 0;
    }
    return fac[n] * invfac[m] % MOD * invfac[n-m] % MOD;
}

void precalc_facs() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = inv(fac[i]);
    }
}

ll a[MAXN], pa[MAXN], p3[2 * MAXN], p2[2 * MAXN], sp[MAXN], spp[MAXN];

int main() {
    precalc_facs();
    cin >> n;
    n /= 2;
    p3[0] = 1;
    p2[0] = 1;
    for (int i = 0; i <= 2 * n; i++) {

        p3[i+1] = p3[i] * 3 % MOD;
        p2[i+1] = p2[i] * 2 % MOD;
    }

    for (int i = 0; i <= n; i++) {
        sp[i] = p2[n-i] * C(n, i) % MOD;
        spp[i+1] = (spp[i] + sp[i]) % MOD;
    }

    for (int i = 0; i <= n; i++) {
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = sp[i] * (p3[n] - (spp[n - i + 1] - spp[0])) % MOD;
        ans = (ans + sum) % MOD;
        //cout << ans << endl;
    }
    cout << (p3[n*2] - ans * 2 + MOD * 2) % MOD << endl;


    return 0;
}