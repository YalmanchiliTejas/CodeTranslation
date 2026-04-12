#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

// ans = sum((-1) ^ i * comb(n, i) * ways[i]), i = 0, ..., n
// ways[i] = seturi de ramen care au topingurile 1, ..., i in cel mult un ramen
// ways2[i][j] = pui i topinguri in j ramen
// ways[i] = sum(ways2[i][j]) * (2 ^ ((n - i) * j)) * 2 ^ (2 ^ (n - i)), j = 0, ..., n

const int MAXN = 3000;

int fact[MAXN + 1], invfact[MAXN + 1];
int p2[MAXN + 1], invp2[MAXN + 1];

inline void mod(int &x, int md) {
    if(x < 0)
        x += md;
    if(x >= md)
        x -= md;
}

inline int lgput(int a, int b, int md) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % md;
        b >>= 1;
        a = (1LL * a * a) % md;
    }
    return ans;
}

inline void prec(int n, int md) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % md;
    }
    invfact[n] = lgput(fact[n], md - 2, md);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % md;
    }
    p2[0] = invp2[0] = 1;
    for(int i = 1; i <= n; i++) {
        p2[i] = 2 * p2[i - 1];
        mod(p2[i], md);
        invp2[i] = 2 * invp2[i - 1];
        mod(invp2[i], md - 1);
    }
}

inline int comb(int n, int k, int md) {
    return (1LL * fact[n] * ((1LL * invfact[k] * invfact[n - k]) % md)) % md;
}

int ways2[MAXN + 1][MAXN + 1];
int ways[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, md;
    ios::sync_with_stdio(false);
    cin >> n >> md;
    prec(n, md);
    for(i = 0; i <= n; i++) {
        ways2[i][0] = 1;
        for(j = 1; j <= i; j++) {
            ways2[i][j] = (1LL * ways2[i - 1][j] * (j + 1) + ways2[i - 1][j - 1]) % md;
        }
    }
    for(i = 0; i <= n; i++) {
        int cur_p2 = 1;
        int cur_invp2 = lgput(2, invp2[n - i], md);
        for(j = 0; j <= i; j++) {
            int cur = (1LL * cur_p2 * cur_invp2) % md;
            ways[i] = (ways[i] + 1LL * cur * ways2[i][j]) % md;
            cur_p2 = (1LL * cur_p2 * p2[n - i]) % md;
        }
    }
    int ans = 0;
    for(i = 0; i <= n; i++) {
        if(i % 2 == 0)
            ans += (1LL * comb(n, i, md) * ways[i]) % md;
        else
            ans -= (1LL * comb(n, i, md) * ways[i]) % md;
        mod(ans, md);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
