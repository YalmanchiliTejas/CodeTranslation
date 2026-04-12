#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}

using vi = vector<int>;

#define P (1'000'000'007)

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    capi(n);

    auto res = 1 + (n % 2);
    int dp[200001][3];

    rep(j, res + 1) {
        dp[0][j] = 0;
    }

    rep(i, n) {
        capi(a);
        
        if ((i + 1) % 2 == 0) {
            dp[i + 1][0] = dp[i][0];
        } else {
            dp[i + 1][0] = dp[i][0] + a;
        }

        rep(j, res) {
            if (j > i) {
                dp[i + 1][j + 1] = 0;
            } else if ((i + j) % 2 == 0) {
                dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1]);
            } else {
                dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1] + a);
            }
        }
    }

    cout << dp[n][res];

    return 0;
}