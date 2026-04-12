#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int k;
    cin >> k;
    int n = S.length();

    vector<vector<vector<int64_t>>> DP(n + 1, vector<vector<int64_t>>(k + 2, vector<int64_t>(2)));
    DP[0][0][0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            for (int l = 0; l < 10; l++){
                if (S[i] - '0' == l)
                    DP[i + 1][j + min(1, l)][0] += DP[i][j][0];
                else if (l < S[i] - '0')
                    DP[i + 1][j + min(1, l)][1] += DP[i][j][0];
                DP[i + 1][j + min(1, l)][1] += DP[i][j][1];
            }
        }
    }

    cout << DP[n][k][0] + DP[n][k][1] << endl;
}
