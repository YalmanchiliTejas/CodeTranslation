#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

const int MOD = 998244353;
const int N = 1e4 + 10;
typedef long long ll;

int n, dp[N][N], inv[N], fact[N], ifact[N];
string a,b;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {

    inv[1] = 1;
    for (int n = 2; n < N; n++) {
        inv[n] = ll(MOD - MOD/n) * inv[MOD%n] % MOD;
        assert(ll(n) * inv[n] % MOD == 1);
    }
    fact[0] = ifact[0] = 1;
    for (int n = 1; n < N; n++) {
        fact[n] = (ll) n * fact[n-1] % MOD;
        ifact[n] = (ll) inv[n] * ifact[n-1] % MOD;
    }

    cin >> a >> b;
    n = a.size();

    int x = 0, y = 0;
    forn(i,n) if (a[i] == '1') {
        if (b[i] == '0') y++;
        else x++;
    }

    forn(i,x+1) forn(j,y+1) {
        if (i == 0 && j == 0) dp[i][j] = 1;
        else {
            dp[i][j] = 0;
            if (i && j) add(dp[i][j], (ll) dp[i-1][j] * i%MOD * j%MOD);
            if (j) add(dp[i][j], (ll) dp[i][j-1] *j%MOD *j%MOD);
        }
    }

    int coef = 1, ans = 0;
    forn(k,x+1) {
        add(ans, (ll) coef * dp[x-k][y] % MOD);
        coef = (ll) coef * (x-k) % MOD;
        coef = (ll) coef * (x+y-k) % MOD;
    }
    cout << ans << endl;

    return 0;
}
