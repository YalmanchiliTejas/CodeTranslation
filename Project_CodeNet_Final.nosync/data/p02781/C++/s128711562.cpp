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
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int K;
    cin >> K;

    LL dp[105][10][2] = {};
    if(s[0] == '1') {
        dp[0][0][0] = 1;
        dp[0][1][1] = 1;
    } else {
        dp[0][0][0] = dp[0][1][1] = 1;
        dp[0][1][0] = s[0] - '0' - 1;
    }

    for(int i = 1; i < s.size(); ++i) {
        int d = s[i] - '0';
        for(int j = 0; j <= K; ++j) {
            if(d == 0) {
                dp[i][j][1] += dp[i - 1][j][1];
            } else {
                dp[i][j][0] += dp[i - 1][j][1];
                if(j != 0){
                    dp[i][j][1] += dp[i - 1][j - 1][1];
                    dp[i][j][0] += dp[i - 1][j - 1][1] * (d - 1);
                }
            }
            dp[i][j][0] += dp[i - 1][j][0];
            if(j != 0) {
                dp[i][j][0] += dp[i - 1][j - 1][0] * 9;
            }
        }
    }
    cout << dp[s.size() - 1][K][0] + dp[s.size() - 1][K][1] << endl;

    return 0;
}
