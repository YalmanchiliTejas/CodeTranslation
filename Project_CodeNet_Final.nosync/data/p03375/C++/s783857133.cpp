#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
ifstream ifs("in.txt");
ofstream ofs("out.txt");
#define cin ifs
#define cout ofs
//*/

//拡張ユークリッドの互除法
int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

// mod逆元
int mod_inverse(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int N, M;
int dp[3333][3333];
int fact[3333], fact_inv[3333];
int exp_2[9999999], exp_2_2[3333];

signed main() {
    cin >> N >> M;
    fact[0] = 1;
    fact_inv[0] = 1;
    exp_2_2[0] = 2;
    for (int i = 1; i < 3333; i++) {
        fact[i] = fact[i - 1] * i % M;
        fact_inv[i] = mod_inverse(fact[i], M);
        exp_2_2[i] = exp_2_2[i - 1] * exp_2_2[i - 1] % M;
    }
    exp_2[0] = 1;
    for (int i = 1; i < 9999999; i++) {
        exp_2[i] = exp_2[i - 1] * 2 % M;
    }
    for (int i = 0; i < 3333; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < 3333; i++) {
        for (int k = 1; k < 3333; k++) {
            dp[i][k] = (dp[i - 1][k - 1] + dp[i - 1][k] + dp[i - 1][k] * k) % M;
        }
    }
    int ans = 0;
    int sign = -1;
    for (int i = 0; i <= N; i++) {
        sign *= -1;
        int comb = fact[N] * fact_inv[i] % M * fact_inv[N - i] % M;
        int ways = 0;
        for (int k = 0; k <= i; k++) {
            (ways += dp[i][k] * exp_2[k * (N - i)] % M) %= M;
        }
        (ways *= exp_2_2[N - i]) %= M;
        (ans += sign * (comb * ways % M) + M) %= M;
    }
    cout << ans << endl;
}