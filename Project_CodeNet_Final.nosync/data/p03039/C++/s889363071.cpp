#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

const int MAX_N = 400000;

ll inv[MAX_N], fac[MAX_N], fiv[MAX_N];
void COMinit() {
    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }
}

ll com(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * fiv[k] % MOD * fiv[n-k] % MOD;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, K;
    cin >> n >> m >> K;

    ll X = n * m;

    ll tate = 0;
    for (ll i = 1; i < m; i++) {
        tate += i * (m - i);
        tate %= MOD;
    }
    tate = 2 * n * n % MOD * tate % MOD;

    ll yoko = 0;
    for (ll i = 1; i < n; i++) {
        yoko += i * (n - i);
        yoko %= MOD;
    }
    yoko = 2 * m * m % MOD * yoko % MOD;

    ll ans = (yoko + tate) % MOD;

    COMinit();
    ans = ans * com(X - 2, K - 2) % MOD;
    if (ans % 2 == 0) ans /= 2;
    else ans = (ans + MOD) / 2;

    cout << ans << "\n";
    return 0;
}