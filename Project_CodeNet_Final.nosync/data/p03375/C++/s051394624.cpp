#include<bits/stdc++.h>
using namespace std;

int N, M;

int exp(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % M;
        x = 1LL * x * x % M;
        n >>= 1;
    }
    return ret;
}
int inv(int x) {
    return exp(x, M - 2);
}
int po1[3010], po2[3010], ppo[3010], fact[3010], invf[3010], prec[3010][3010];
int comb(int n, int k) {
    return 1LL * fact[n] * invf[k] % M * invf[n - k] % M;
}

int X;

int cc[3010][3010];
int dp(int n, int k) {
    int &ret = cc[n][k];
    if(ret != -1) return ret;
    if(n == 0) return ret = k == 0;

    ret = 0;
    if(k) {
        ret += dp(n - 1, k - 1);
        ret %= M;
    }
    ret += 1LL * dp(n - 1, k) * k % M;
    ret %= M;
    return ret;
}

int main() {
    cin >> N >> M;

    po1[0] = 1;
    for(int i = 1; i < 3010; i++) {
        po1[i] = 1LL * po1[i - 1] * 2 % M;
    }
    po2[0] = 1;
    for(int i = 1; i < 3010; i++) {
        po2[i] = 1LL * po2[i - 1] * 2 % (M - 1);
    }
    for(int i = 0; i < 3010; i++) {
        ppo[i] = exp(2, po2[i]);
    }
    fact[0] = 1;
    for(int i = 1; i < 3010; i++) {
        fact[i] = 1LL * fact[i - 1] * i % M;
    }
    for(int i = 0; i < 3010; i++) {
        invf[i] = inv(fact[i]);
    }
    for(int i = 0; i < 3010; i++) {
        prec[i][0] = 1;
        for(int j = 1; j < 3010; j++) {
            prec[i][j] = 1LL * prec[i][j - 1] * po1[i] % M;
        }
    }

    memset(cc, -1, sizeof(cc));

    int ans = 0;
    for(int i = 0; i <= N; i++) {
        X = N - i;

        int tmp = 0;
        if(!i) tmp++;
        for(int j = 1; j <= i; j++) {
            tmp += 1LL * dp(i, j) * prec[X][j] % M;
            tmp %= M;
            tmp += 1LL * dp(i, j) * j % M * prec[X][j - 1] % M;
            tmp %= M;
        }

        //cout << ppo[X] << ' ' << comb(N, i) << ' ' << tmp << endl;

        if(i % 2) {
            ans += M - 1LL * ppo[X] * comb(N, i) % M * tmp % M;
            ans %= M;
        }
        else {
            ans += 1LL * ppo[X] * comb(N, i) % M * tmp % M;
            ans %= M;
        }
    }

    printf("%d", ans);
}
