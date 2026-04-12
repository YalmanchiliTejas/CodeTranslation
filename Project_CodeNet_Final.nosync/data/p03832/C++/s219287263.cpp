
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
using namespace std;

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }

const int MOD = 1e9 + 7;

int f[1011][1011], C[1011][1011], gt[1011], inv_gt[1011];
void add(int& f, int val) {
    f += val;
    if (f >= MOD) f -= MOD;
}

int power(int x, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = res * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return res;
}

int inverse(int x) {
    return power(x, MOD  - 2);
}

#undef int
int main() {
#define int long long
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (fixed) << setprecision(9);

    gt[0] = 1;
    FOR(i,1,1000) gt[i] = gt[i-1] * i % MOD;
    FOR(i,0,1000) inv_gt[i] = inverse(gt[i]);

    int n, a, b, c, d;
    C[0][0] = 1;
    FOR(i,1,1000) {
        C[i][0] = 1;
        FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    while (GI(n) == 1) {
        GI(a); GI(b); GI(c); GI(d);
        memset(f, 0, sizeof f);

        f[0][a-1] = 1;
        FOR(i,0,n) FOR(t,a-1,b-1) {
            int cur = f[i][t];
            if (!cur) continue;

            // do not use t+1
            add(f[i][t+1], cur);

            // use t+1
            int mul = 1;
            for(int j = i+t+1, g = 1; j <= n && g <= d; g++, j += t+1) {
                mul = mul * C[n-(j-t-1)][t+1] % MOD;
                if (g >= c) {
                    add(f[j][t+1], cur * mul % MOD * inv_gt[g] % MOD);
                }
            }
        }
        /*
        FOR(i,1,n) FOR(t,a,b) {
            // do not use t
            add(f[i][t], f[i][t-1]);
            // use some t
            for(int mul=c, j=i-c*t; j >= 0 && mul <= d; mul++, j -= t) {
                add(f[i][t], f[j][t-1]);
            }
        }
        */
        cout << f[n][b] << endl;
    }
}
