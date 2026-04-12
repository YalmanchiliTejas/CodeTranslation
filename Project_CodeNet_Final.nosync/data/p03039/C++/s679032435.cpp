#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int modpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int comb(int n, int k) {
    int p = 1, q = 1;
    for (int i = 0; i < k; i++) {
        p = mul(p, n - i); // fac[n] / fac[n - k]
        q = mul(q, i + 1); // fac[k]
    }
    return mul(p, modpow(q, mod - 2));
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    // i * (n - i) * m * m
    for (int i = 1; i < n; i++) {
        add(ans, mul(mul(i, n - i), mul(m, m)));
    }
    for (int i = 1; i < m; i++) {
        add(ans, mul(mul(i, m - i), mul(n, n)));
    }
    ans = mul(ans, comb(n * m - 2, k - 2));
    cout << ans << endl;
    return 0;
}
