/*
author: thanglong
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
typedef pair<int, int> ii;
 
const int N = 3e3 + 5;
 
int n, mod, f[N][N], c[N][N], pw[N * N], pw2[N], dp[N], ans;
 
void calc() {
    //f[i][j]:the number of ways to "put" i guys in j bowl
    for(int i = 0; i <= N - 5; i++)
        f[i][0] = 1;
    for(int i = 1; i <= N - 5; i++) {
        for(int j = 1; j <= i; j++)
            f[i][j] = ((1ll * (j + 1) * f[i - 1][j]) % mod + f[i - 1][j - 1]) % mod;
    }
    c[0][0] = 1;
    for(int i = 1; i <= N - 5; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    pw[0] = 1;
    for(int i = 1; i <= (N - 5) * (N - 5); i++)
        pw[i] = (1ll * pw[i - 1] * 2) % mod;
    pw2[0] = 2;
    for(int i = 1; i <= N - 5; i++)
        pw2[i] = (1ll * pw2[i - 1] * pw2[i - 1]) % mod;
    ans = pw2[n] - 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++) {
            //cout << f[i][j] << " " << i << " " << j << "\n";
            int val = (1ll * f[i][j] * pw[(n - i) * j]) % mod;
            if(j == 0)
                dp[i] += (1ll * val * (pw2[n - i] - 1)) % mod;
            else
                dp[i] += (1ll * val * pw2[n - i]) % mod;
            dp[i] %= mod;
        }
        if(i % 2 == 0)
            ans = (ans + (1ll * dp[i] * c[n][i]) % mod) % mod;
        else
            ans = (ans - (1ll * dp[i] * c[n][i]) % mod) % mod;
        ans = (ans + mod) % mod;
    }
    cout << ans;
    exit(0);
}
 
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> mod;
    calc();
}