#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int dp[101][2][6];

int main() {
    string N;
    int K,l;
    cin >> N >> K;
    l = N.size();

    dp[0][0][1] = 1;
    rep(i,l) {
        int d=N.at(i)-'0';
        rep(j,2)
            rep(k,K+2)
                rep(m,(j?9:d)+1)
                    dp[i+1][j||m<d][k+(m!=0)] += dp[i][j][k];
    }

    cout << dp[l][0][K+1]+dp[l][1][K+1] << endl;
}