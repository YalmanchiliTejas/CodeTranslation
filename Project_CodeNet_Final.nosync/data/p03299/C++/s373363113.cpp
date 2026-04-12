#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MN = 111;

int exp(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ret;
}

int N;
int H[MN], mnp[MN][MN];

int cc[MN][MN][MN][2];
int dp(int l, int r, int p, int t) {
    if(l > r) return 1;
    int &ret = cc[l][r][p][t];
    if(ret != -1) return ret;

    ret = 0;
    int h = p == N? 1 : H[p];
    int x = mnp[l][r];
    int d = H[x] - h;
    if(t) {
        ret += 1LL * dp(l, x - 1, x, 1) * dp(x + 1, r, x, 1) % mod * 2 % mod;
        ret %= mod;
        ret += 1LL * dp(l, x - 1, x, 0) * dp(x + 1, r, x, 0) % mod * (exp(2, d) + mod - 1) % mod * 2 % mod;
        ret %= mod;
    }
    else {
        ret += 1LL * dp(l, x - 1, x, 0) * dp(x + 1, r, x, 0) % mod * exp(2, d) % mod;
        ret %= mod;
    }

    //cout << l << ' ' << r << ' ' << p << ' ' << t << ' ' << ret << endl;

    return ret;
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    for(int i = 0; i < N; i++) {
        int mn = 2e9, p = -1;
        for(int j = i; j < N; j++) {
            if(mn > H[j]) mn = H[j], p = j;
            mnp[i][j] = p;
        }
    }

    memset(cc, -1, sizeof(cc));
    printf("%d", dp(0, N - 1, N, 1));
}
