#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1000000000000000000L;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}

unordered_map<ll, ll> memo;

ll inv(ll a) {
    if(memo.find(a) != memo.end()) return memo[a];
    ll x, y;
    extgcd(a, MOD, x, y);
    return memo[a] = (x + MOD) % MOD;
}

ll f[1001];
ll dp[1001][1001];

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    f[0] = 1;
    rep(i, n) {
        f[i + 1] = f[i] * (i + 1) % MOD;
    }

    rep(i, n + 1) rep(j, n + 1) dp[i][j] = 0;
    dp[a - 1][0] = 1;
    for(int i = a; i <= b; i++) {
        rep(j, n + 1) {
            dp[i][j] += dp[i - 1][j];
            ll in = 1;
            ll invf = inv(f[i]);
            rep(k, c) {
                in = in * invf % MOD;
            }
            for(int k = c; k <= min(d, j / i); k++) {
                ll tmp = f[n - j + i * k] * inv(f[n - j]) % MOD;
                tmp = tmp * in % MOD;
                in = in * invf % MOD;
                tmp = tmp * inv(f[k]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i * k] * tmp % MOD) % MOD;
            }
        }
    }

    /*
    rep(i, n + 1) {
        rep(j, n + 1) {
            cout << " " << dp[i][j];
        }
        cout << endl;
    }
    */

    cout << dp[b][n] % MOD << endl;
}
