#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
typedef pair<int, int> pii;
const int mod = int(1e9) + 7;

int Pow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return res;
}

int fac[N], rev[N], n, m, k;

int nCk(int n, int k) {return 1ll * fac[n] * rev[k] % mod * (ll)rev[n - k] % mod;}
void add(int& x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}
int sum(int x, int y) {add(x, y); return x;}
int mul(int x, int y) {
    int res = 1ll * x * y % mod;
    if(res < 0) res += mod;
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    fac[0] = rev[0] = 1;
    for(int i = 1; i <= n * m; ++i) {
        fac[i] = (ll)fac[i - 1] * i % mod;
        rev[i] = Pow(fac[i], mod - 2);
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            add(res, mul(mul(i, (i - 1) * m + j - 1), nCk(n * m - 2, k - 2)));
            add(res, mul(mul(-i, (n - i) * m + m - j), nCk(n * m - 2, k - 2)));
        }
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            add(res, mul(mul(i, (i - 1) * n + j - 1), nCk(n * m - 2, k - 2)));
            add(res, mul(mul(-i, (m - i) * n + n - j), nCk(n * m - 2, k - 2)));
        }
    }
    cout << res;
}
