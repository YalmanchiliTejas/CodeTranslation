#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int dp[105][4][2];

int main() {
    string S;
    int K;
    cin >> S >> K;

    dp[0][0][0] = 1;
    rep(i,S.size())rep(j,4)rep(k,2){
        int nd = S[i] - '0';
        rep(d,10){
            int ni = i + 1;
            int nj = j;
            if (d != 0) {
                nj = j + 1;
            }
            if ( nj > K ) {
                continue;
            }

            int nk = k;
            if (k == 0 && d > nd) {
                continue;
            }
            if (d < nd) {
                nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[S.size()][K][0] + dp[S.size()][K][1] << endl;
}
