#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pll;

#define pb push_back
#define mp make_pair
#define all(_c) _c.begin(), _c.end()

const int MOD = 1e9 + 7;

string k;
int dp[10001][100][2], d, n;

int f(int i, int rem, int sm) {
    if (i == n) {
        return rem == 0;
    }

    int& ret = dp[i][rem][sm];
    if (ret != -1)
        return ret;

    ret = 0;

    if (sm) {
        for (int j = 0; j <= 9; j++)
            ret = (ll(ret) + f(i + 1, (rem + j) % d, 1)) % MOD;
    } else {
        int dig = (k[i] - '0');
        for (int j = 0; j < dig; j++)
            ret = (ll(ret) + f(i + 1, (rem + j) % d, 1)) % MOD;
        ret = (ll(ret) + f(i + 1, (rem + dig) % d, 0)) % MOD;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> d;
    n = k.length();

    memset(dp, -1, sizeof dp);
    cout << (f(0, 0, 0) - ll(1) + MOD) % MOD << '\n';
    return 0;
}
