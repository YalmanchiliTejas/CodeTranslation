#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

LL fac[SIZE], finv[SIZE], inv[SIZE];
void combInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < SIZE; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;

    }
}

LL comb(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;

}

LL Bin(LL n, LL k) {
    if(k < 0 || n < k) {
        return 0;

    }
    LL ret = 1;
    for(LL i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;

    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    combInit();
    LL n, m, k;
    cin >> n >> m >> k;
    
    LL res = 0;
    for(int i = 0; i <= n - 1; ++i) {
        for(int j = 0; j <= m - 1; ++j) {
            LL tmp = (n - i) * (m - j) * (i + j) % MOD;
            if(i != 0 && j != 0) tmp *= 2;
            res += tmp;
            res %= MOD;

        }
    }
    cout << res * comb(n * m - 2, k - 2) % MOD << endl;

    return 0;
}

