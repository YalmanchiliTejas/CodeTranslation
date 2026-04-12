#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

string N;
ll dp[1010101][5][2];
int K;

ll solve(int i, int k, int b) {
    ll& ret = dp[i][k][b];

    if (i >= N.size()) {
        return (k == K);
    }
    if (ret != 1e18) return ret;

    int x = N[i] - '0';
    ret = 0;

    // 一番上の桁
    if (i == 0) {

        // 自由度trueで下の桁へ
        ret += solve(i+1, 1, true) * (x - 1) + solve(i+1, 0, true);

        // 自由度falseで下の桁へ
        return ret += solve(i+1, 1, false);
    }
    else {
        // 自由度true
        if (b) {
            //
            return ret += solve(i+1, k, b) + solve(i+1, k+1, b) * 9;
        }
        else {
            // 0だったら
            if (x == 0) {
                ret += solve(i+1, k, b);
            }
            else {
                ret += solve(i+1, k+1, b) + solve(i+1, k, !b) + solve(i+1, k+1, !b) * (x - 1);
            }
        }
    }
    return ret;
}

int main() {
    cin >> N >> K;
    rep(i, N.size()+1) rep(j, K+1) rep(b, 2) dp[i][j][b] = 1e18;

    cout << solve(0, 0, false) << endl;
}
