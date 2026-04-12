#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;


string N;
ll dp[110][110][2];
int K;

ll solve(int i, int k, int b) {

    if (i >= N.size()) {
        return (k == K);
    }

    ll& ret = dp[i][k][b];
    if (~ret) return ret;

    ll d = N[i] - '0';
    ret = 0;

    // 自由度がある
    if (b) {
        // すべての数字を使える
        ret += solve(i+1, k, b) + solve(i+1, k+1, b) * 9LL;
    }
    else {
        // 自由度がない
        if (d == 0) {
            return ret += solve(i+1, k, b);
        }
        else {
            return ret += solve(i+1, k, !b) + solve(i+1, k+1, !b) * (d - 1) + solve(i+1, k+1, b);
        }
    }

    return ret;
}

int main() {
    cin >> N >> K;
    rep(i, 110) rep(j, 110) rep(k, 2) dp[i][j][k] = -1;
    cout << solve(0, 0, false) << endl;
}
