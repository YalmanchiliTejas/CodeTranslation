#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int n, MOD;

ll bp(ll a, ll p, ll m = MOD) {
    ll r = 1;
    while (p > 0) {
        if (p & 1)
            r = r * a % m;
        a = a * a % m;
        p >>= 1;
    }
    return r;
}

const int N = 3005;
ll c[N][N], w[N][N], two[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> MOD;

    for (int i = 0; i <= n; i++) {
        ll x = bp(2, n - i), y = 1;
        for (int j = 0; j <= n; j++) {
            two[i][j] = y;
            y = y * x % MOD;
        }
    }

    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    for (int i = 0; i <= n; i++) {
        w[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = (w[i][j - 1] * (i + 1) + w[i - 1][j - 1]) % MOD;
        }
    }

    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        ll cur = 0;

        for (int k = 0; k <= i; k++) {
            cur = (cur + w[k][i] * two[i][k]) % MOD;
        }

        cur = cur * c[n][i] % MOD * bp(2, bp(2, n - i, MOD - 1)) % MOD;

        if (i % 2)
            ans = (ans - cur + MOD) % MOD;
        else
            ans = (ans + cur) % MOD;
    }

    cout << ans;

    return 0;
}