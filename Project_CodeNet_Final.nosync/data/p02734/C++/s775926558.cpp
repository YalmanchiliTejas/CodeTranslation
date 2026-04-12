
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

int dp[3001][3001][3] = {0};

#define P (998244353)

signed main() {
    int n, s;
    cin >> n >> s;

    vi va;
    rep(i, n) {
        capi(a);
        va.push_back(a);
    }

    dp[0][0][0] = 1;

    rep(i, n) {
        rep(j, s + 1) {
            (dp[i + 1][j][0] += dp[i][j][0]) %= P;
            (dp[i + 1][j][1] += dp[i][j][1]) %= P;
            (dp[i + 1][j][2] += dp[i][j][2]) %= P;
            if (va[i] + j <= s) {
                (dp[i + 1][va[i] + j][1] += dp[i][j][1]) %= P;
                (dp[i + 1][va[i] + j][1] += dp[i][j][0] * (i + 1)) %= P;
                (dp[i + 1][va[i] + j][2] += dp[i][j][0] * (n - i) * (i + 1)) %= P;
                (dp[i + 1][va[i] + j][2] += dp[i][j][1] * (n - i)) %= P;
            }
        }
    }

    cout << dp[n][s][2];

    return 0;
}