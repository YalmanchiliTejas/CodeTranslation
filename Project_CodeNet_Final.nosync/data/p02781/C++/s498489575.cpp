#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;

long long nzero_cnt(string N, int K) {
    int L = N.size();

    vector <vector<vector<long long>>> dp(L + 1, vector<vector<long long>>(K + 1, vector<long long>(2)));
    //dp[i桁番目まで確定][非ゼロの個数][N未満確定]
    dp[0][0][0] = 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 2; k++) {
                for (int d = 0; d <= (k ? 9 : N[i] - '0'); d++) {
                    if (j == K && d != 0) continue;
                    int temp = 0;
                    if (d != 0)temp = 1;
                    //cout << d<<" ";

                    dp[i + 1][j+temp][k || (d < N[i]-'0')] += dp[i][j][k];
                }
                //cout << endl;
            }
        }
    }
    /*
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 2; k++)
                printf("dp[%d][%d][%d]=%lld ", i, j, k, dp[i][j][k]);
        }
        cout << endl;
    }
    */
    return dp[L][K][1] + dp[L][K][0];
}

int main() {
    string  N;
    int K;
    cin >> N >> K;

    
    cout << nzero_cnt(N,K) << endl;
}
