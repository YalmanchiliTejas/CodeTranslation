#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

#define int ll

int dp[2001][2001];
ll inv(int now) {
    int b = MAX_MOD - 2LL;
    int ans = 1;
    while (b) {
        if (b % 2) {
            ans *= now;
            ans %= MAX_MOD;
        }
        now *= now;
        now %= MAX_MOD;
        b /= 2LL;
    }
    return ans;
}

int comb(int a, int b) {
    int ans = 1;
    for (int i = 1; i <= b; ++i) {
        ans *= (a - i + 1LL) % MAX_MOD;
        ans %= MAX_MOD;
        ans *= inv(i);
        ans %= MAX_MOD;
    }
    return ans;
}

void solve(){
    while (true) {
        int n, d, x;
        cin >> n >> d >> x;
        if (n == 0) return;

        REP(i, n) {
            for (int q = i; q <= n; ++q) {
                dp[i][q] = 0;
            }
        }
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            ll hoge = 0;
            for (int q = i+1; q <= n; ++q) {
                hoge += dp[i][q - 1];
                if (q - x >= 0) {
                    hoge += MAX_MOD - dp[i][q - x];
                }
                hoge %= MAX_MOD;
                dp[i + 1][q] = hoge;
            }
        }

        int ans = 0;
        for (int i = 1; i <= min(n,d); ++i) {
            ans += dp[i][n] * comb(d, i) % MAX_MOD;
            ans %= MAX_MOD;
        }
        cout << ans << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}
