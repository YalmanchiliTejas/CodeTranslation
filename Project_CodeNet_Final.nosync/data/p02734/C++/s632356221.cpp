#include <bits/stdc++.h>
#define LL long long

const int N = 3e3 + 5;
const int mod = 998244353;

int n, s;
int a[N];
LL f[N][N][3];

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    f[0][0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= s; ++j) {
            f[i][j][0] = (f[i][j][0] + f[i - 1][j][0]) % mod;
            f[i][j][1] = (f[i][j][1] + f[i - 1][j][0] + f[i - 1][j][1]) % mod;
            f[i][j][2] = (f[i][j][2] + f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2]) % mod;
            if(j + a[i] <= s) {
                f[i][ j + a[i] ][1] = (f[i][ j + a[i] ][1] + f[i - 1][j][0] + f[i - 1][j][1]) % mod;
                f[i][ j + a[i] ][2] = (f[i][ j + a[i] ][2] + f[i - 1][j][0] + f[i - 1][j][1]) % mod;
            }
        }
    }
    printf("%lld", f[n][s][2]);
    return 0;
}
