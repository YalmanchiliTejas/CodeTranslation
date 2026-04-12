#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////

ll dp[110][2][110];

int main() {
    string s; cin >> s;
    int K; cin >> K;

    int len = s.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    rep(i,len) {
        int d = s[i] - '0';
        rep(j,2) rep (k, K+1) {
            for (int l = 0; l <= (j ? 9 : d); l++) {
                if (l != 0) dp[i+1][j || (l<d)][k+1] += dp[i][j][k];
                else dp[i+1][j || (l<d)][k] += dp[i][j][k];
            }
        }
    }

    cout << dp[len][1][K] + dp[len][0][K] << endl;

    return 0;
}