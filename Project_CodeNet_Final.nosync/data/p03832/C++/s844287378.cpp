#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int fac[4040], fac_inv[4040];
const int mod = 1000000007;

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)res *= a;
        a *= a;
        res %= mod;
        a %= mod;
        b /= 2;
    }
    return res;
}

int inv(int x) {
    return pow(x, mod - 2);
}

void calc() {
    fac[0] = 1;
    fac_inv[0] = 1;
    for (int i = 1; i < 4040; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        fac_inv[i] = inv(fac[i]);
    }
}

int Comb(int n, int r) {
    return fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod;
}

int H(int n, int r) {
    return Comb(n + r - 1, r);
}
//calcを必ず実行
//mod書き換え
//fac,facinv配列長書き換え

int N;
int A, B, C, D;
int memo[1010][1010];
int cnt;

int rec(int remain, int group) {
    if (remain < 0) {
        return 0;
    }
    if (remain == 0) {
        return fac[N];
    }
    if (group == A - 1) {
        if (remain == 0) {
            return fac[N];
            /*
            int tmp = fac[N];
            for (int g = A; g <= B; ++g) {
                tmp *= pow(fac_inv[g], Num[g]);
                tmp %= mod;
                tmp *= fac_inv[Num[g]];
                tmp %= mod;
            }
            ans += tmp;
            ans %= mod;
             */
        } else {
            return 0;
        }
    }
    if (memo[remain][group] != -1) {
        return memo[remain][group];
    }
    int res = rec(remain, group - 1);
    for (int k = C; k <= D && remain - k * group >= 0; ++k) {
        int tmp = rec(remain - k * group, group - 1);
        tmp *= pow(fac_inv[group], k);
        tmp %= mod;
        tmp *= fac_inv[k];
        tmp %= mod;
        res += tmp;
    }
    res %= mod;
    return memo[remain][group] = res;
}

signed main() {
    calc();
    memset(memo, -1, sizeof(memo));
    cin >> N >> A >> B >> C >> D;
    int ans = rec(N, B);
    cout << ans << endl;
    return 0;
}
