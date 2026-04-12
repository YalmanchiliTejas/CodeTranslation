#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll dp[110][110][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string n;
    int k;
    cin >> n >> k;
    dp[0][0][0] = 1;
    int m = n.size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= m; j++) {
            int lim = n[i] - '0';
            // flg == 1
            for(int k = 0; k < 10; k++) {
                if(k == 0) {
                    dp[i + 1][j][1] += dp[i][j][1];
                } else {
                    dp[i + 1][j + 1][1] += dp[i][j][1];
                }
            }
            // flg == 0
            for(int k = 0; k <= lim; k++) {
                if(k == lim) {
                    if(k == 0) {
                        dp[i + 1][j][0] += dp[i][j][0];
                    } else {
                        dp[i + 1][j + 1][0] += dp[i][j][0];
                    }
                } else {
                    if(k == 0) {
                        dp[i + 1][j][1] += dp[i][j][0];
                    } else {
                        dp[i + 1][j + 1][1] += dp[i][j][0];
                    }
                }
            }
        }
    }
    cout << dp[m][k][0] + dp[m][k][1] << endl;
}