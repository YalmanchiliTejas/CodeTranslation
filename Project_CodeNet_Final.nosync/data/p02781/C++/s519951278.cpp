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

#define P (1'000'000'007)

int dp[101][4];
int dp2[101][4];

signed main() {
    string s;
    int k;
    cin >> s >> k;

    dp[0][0] = 1;

    rep(i, s.size()) {
        int d = s[i] - '0';
        if (i == 0) {
            dp[1][0] = 1;
            dp[1][1] = d - 1;
            dp2[1][1] = 1; 
        } else {
            if (d == 0) {
                rep(j, 4) {
                    if (j + 1 <= 3) dp[i + 1][j + 1] += dp[i][j] * 9;
                    dp[i + 1][j] += dp[i][j];
                    dp2[i + 1][j] += dp2[i][j];
                }
            } else {
                rep(j, 3) {
                    dp[i + 1][j + 1] += dp[i][j] * 9 + dp2[i][j] * (d - 1) + dp2[i][j + 1];
                    dp2[i + 1][j + 1] += dp2[i][j];
                }
                rep(j, 4) {
                    dp[i + 1][j] += dp[i][j];
                }
            }
        }
    }

    cout << dp[s.size()][k] + dp2[s.size()][k];

    return 0;
}
