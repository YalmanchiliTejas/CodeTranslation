#include<bits/stdc++.h>
using namespace std;
#define N 1000 + 5
#define Mod 1000000007
#define rep(i, l, r) for(int i = l; i <= r; ++i)
int n, A, B, C, D, fac[N], inv[N], c[N][N], P[N][N], dp[N][N];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
int Mul(int a, int b){
    return 1ll * a * b % Mod;
}
int Qpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = Mul(ans, a);
        a = Mul(a, a), b >>= 1;
    }
    return ans;
}
int main(){
    n = read(), A = read(), B = read(), C = read(), D = read();
    fac[0] = inv[0] = 1;
    rep(i, 1, n) fac[i] = Mul(fac[i - 1], i), inv[i] = Qpow(fac[i], Mod - 2);
    rep(i, 0, n) c[i][0] = 1;
    rep(i, 1, n) rep(j, 1, i) c[i][j] = Inc(c[i - 1][j - 1], c[i - 1][j]);
    rep(i, 1, n) rep(j, 1, n) P[i][j] = Qpow(Qpow(fac[i], j), Mod - 2);
    dp[A - 1][0] = 1;
    rep(i, A, B) rep(j, 0, n){
        dp[i][j] = dp[i - 1][j];
        rep(k, C, min(D, j / i))
            dp[i][j] = Inc(dp[i][j], Mul(dp[i - 1][j - i * k], Mul(fac[i * k], Mul(Mul(P[i][k], inv[k]), c[n - j + i * k][i * k]))));
    }
    printf("%d", dp[B][n]);
    return 0;
}