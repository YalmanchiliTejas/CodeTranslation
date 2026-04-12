#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e3 + 5;
const int MOD = 1e9 + 7;

int cmb[DIM][DIM], dp1[DIM][DIM], dp2[DIM][DIM];

int lgput(int x, int n) {
    if (!n)
        return 1;
    
    int y = lgput(x, n >> 1);
    y = (1LL * y * y) % MOD;
    
    if (n & 1)
        y = (1LL * y * x) % MOD;
    
    return y;
}

int main(void) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    for (int i = 0; i <= n; ++i) {
        cmb[i][0] = 1;
        
        for (int j = 1; j <= i; ++j)
            cmb[i][j] = (cmb[i - 1][j - 1] + cmb[i - 1][j]) % MOD;
    }
    
    for (int i = 1; i <= n; ++i) {
        dp2[i][1] = 1;
        
        for (int j = 2; i * j <= n; ++j)
            dp2[i][j] = 1LL * dp2[i][j - 1] * cmb[i * j][i] % MOD * lgput(j, MOD - 2) % MOD;
    }

    for (int i = a; i <= b + 1; ++i)
        dp1[0][i] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = b; j >= a; --j) {
            dp1[i][j] = dp1[i][j + 1];
            
            for (int k = c; k <= d and k * j <= i; ++k)
                dp1[i][j] = (1LL * dp1[i - k * j][j + 1] * cmb[i][k * j] % MOD * dp2[j][k] % MOD + dp1[i][j]) % MOD;
        }
    }
    
    cout << dp1[n][a] << endl;
    return 0;
}