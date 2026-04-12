#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

// dp[桁][未満フラグ][決定した桁の数字の総和をdで割った余り]
ll dp[10000][2][110];

int main() {
    string s; cin >> s;
    int d; cin >> d;

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int len = s.size();
    ll mod = 1e9+7;

    for (int i = 0;i < len; i++) {
        int p = s[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < d; k++) {
                for (int l = 0; l <= (j ? 9 : p); l++) {
                    int nextK = (k+l)%d;
                    dp[i+1][j || (l<p)][nextK] += dp[i][j][k];
                    dp[i+1][j || (l<p)][nextK] %= mod;
                }
            }
        }
    }
    ll ans = (dp[len][0][0] + dp[len][1][0])%mod - 1;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
    return 0;
}