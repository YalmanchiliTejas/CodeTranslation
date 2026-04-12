#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define MAX_N 10000
#define MAX_L 100
const int MOD=1e9+7;
int dp[MAX_N+1][2][MAX_L+2];

int main() {
    int K,l;
    string N;
    cin >> N >> K;
    l = N.size();

    rep(i,l+1)
        rep(j,2)
            rep(k,l+1)
                dp[i][j][k] = 0;

    dp[0][0][1] = 1;
    rep(i,l) {
        int x = N.at(i)-'0';
        rep(j,2)
            rep(k,l+2)
                rep(p,(j?9:x)+1)
                    dp[i+1][j || p<x][k + (p!=0)] += dp[i][j][k];
    }
    
    cout << dp[l][0][K+1]+dp[l][1][K+1] << endl;
}