#include <bits/stdc++.h>

const int N = 10000010;
const int moder = 998244353;

int fac[N], inv[N], invf[N];
int pre[N];
int power[N];

int comb(int n, int m){
    return m < 0 || n < m ? 0 : 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int main(){
    fac[0] = invf[0] = power[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
        power[i] = 2 * power[i - 1] % moder;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n / 2; ++ i){
        pre[i] = ((i ? pre[i - 1] : 0) + 1ll * comb(n / 2, i) * power[i]) % moder;
    }
    int ans = 0;
    for (int i = 0; i <= n / 2; ++ i){
        ans = (ans + 1ll * power[n / 2 - i] * comb(n / 2, i) % moder * (i ? pre[i - 1] : 0)) % moder;
    }
    int ans1 = 1;
    for (int i = 0; i < n; ++ i){
        ans1 = 3ll * ans1 % moder;
    }
    ans1 = (ans1 - 2ll * ans) % moder;
    ans1 += ans1 < 0 ? moder : 0;
    printf("%d\n", ans1);
    return 0;
}
