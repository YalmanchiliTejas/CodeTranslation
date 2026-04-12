#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 998244353;
static const int SIZE = 3005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

// i番目まで見て
// 要素の和がjで
// k = 0 : Lを決めていない
// k = 1 : Lを決めたが、Rを決めていない
// k = 2 : Rを決めた
LL dp[SIZE][SIZE * 2][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> v(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];

    }

    dp[0][0][0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= S; ++j) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][1] += (dp[i][j][0] + dp[i][j][1]) % MOD; dp[i + 1][j][1] %= MOD;
            dp[i + 1][j][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % MOD; dp[i + 1][j][2] %= MOD;

            dp[i + 1][j + v[i]][1] = (dp[i + 1][j + v[i]][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
            dp[i + 1][j + v[i]][2] = (dp[i + 1][j + v[i]][2] + dp[i][j][0] + dp[i][j][1]) % MOD;

        }
    }
    cout << dp[N][S][2] << endl;

    return 0;
}

