#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

long MOD;

long pow(long a, long b, long mod) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// @author: pashka

long Q[3001][3001];
long C[3001][3001];

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cin >> MOD;

    cerr << "1\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                Q[i][j] = j == 0;
            } else if (j == 0) {
                Q[i][j] = 1;
            } else {
                Q[i][j] = (Q[i - 1][j - 1] + Q[i - 1][j] * (j + 1)) % MOD;
            }
//            cout << i << " " << j << " " << Q[i][j] << "\n";
        }
    }

    cerr << "2\n";

    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    cerr << "3\n";

    long ans;
    for (int k = 0; k <= n; k++) {
        long z = pow(2, pow(2, k, MOD - 1), MOD);
        long p2 = 1;
        long dp = pow(2, k, MOD);
        for (int j = 0; j <= n; j++) {
            long w = p2;
            p2 = (p2 * dp) % MOD;
            w = (w * z) % MOD;
            w = (w * Q[n - k][j]) % MOD;
            w = (w * C[n][k]) % MOD;
//            cout << k << " " << j << " " << w << "\n";
            if ((n - k) % 2) {
                w = (MOD - w) % MOD;
            }
            ans = (ans + w) % MOD;
        }
    }

    cerr << "4\n";

    cout << ans;

    return 0;
}