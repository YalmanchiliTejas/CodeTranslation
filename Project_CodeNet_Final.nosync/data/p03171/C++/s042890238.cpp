#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
/* -- template -- */

const int MAX = 1000100;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i)%MOD;//拡張euclid互除法によるi!の逆元計算
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD)%MOD;
}

const int MAX_N = 3100;

ll dp[MAX_N][MAX_N]; //dp[i][j] : 区間[i, j)のみの配列が与えられたときの最善のX-Y

int main() {
    int N; cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    rep(i, N) dp[i][i] = 0;
    for(int len = 1; len <= N; ++len) {
        for(int i = 0; i + len <= N; ++i) {
            int j = i + len;
            if((N - len) % 2 == 0) {//いままで取り出した数が偶数個なら先手
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            }else {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}
