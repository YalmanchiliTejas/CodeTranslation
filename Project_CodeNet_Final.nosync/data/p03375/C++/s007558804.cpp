#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int MOD = (int)1e9 + 7;
int add(int a, int b) {
    int c = a + b;
    if (c >= MOD)c -= MOD;
    else if (c < 0)c += MOD;
    return c;
}
void sadd(int &a, int b) {
    a += b;
    if (a >= MOD)a -= MOD;
    else if (a < 0)a += MOD;
}
int mul(int a, int b) {
    return (int)((long long)a*b%MOD);
}
void smul(int &a, int b) {
    a = (int)((long long)a*b % MOD);
}
int powm(int a, long long k) {
    long long res = 1, b = a;
    while (k) {
        if (k & 1)res = res*b%MOD;
        b = b*b%MOD;
        k >>= 1;
    }
    return (int)res;
}

vector<vector<int>> combinations(int n, int mod) {
    auto res = vector<vector<int>>(n + 1, vector<int>(n + 1));
    rep(i, n + 1) res[i][0] = 1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j)
        res[i][j] = (res[i - 1][j - 1] + res[i - 1][j]) % mod;
    return res;
}

vector<vi> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int N, M;
    while (cin >> N >> M) {
        MOD = M;
        dp = vector<vi>(N + 1, vi(N + 1));
        dp[0][0] = 1;

        for (int a = 1; a <= N; ++a)for (int b = 0; b <= a; ++b) {
            sadd(dp[a][b], dp[a - 1][b]);
            if (b > 0) {
                sadd(dp[a][b], dp[a - 1][b - 1]);
                sadd(dp[a][b], mul(dp[a - 1][b], b));
            }
        }

        vi A(N + 1);
        rep(a, N + 1) {
            MOD = M - 1;
            int p = powm(2, N - a);
            MOD = M;
            int q = powm(2, p);
            rep(b, a + 1) {
                int r = powm(2, (ll)(N - a)*b);
                int s = mul(q, mul(dp[a][b], r));
                sadd(A[a], s);
            }
        }

        auto C = combinations(N, M);

        int re = 0;
        rep(a, N + 1) {
            int p = mul(C[N][a], A[a]);
            if (a % 2)p = mul(p, -1);
            sadd(re, p);
        }
        cout << re << endl;
    }
}