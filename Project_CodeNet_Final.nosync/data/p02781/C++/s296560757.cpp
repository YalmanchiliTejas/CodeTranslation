#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<vector<int64_t>>> DP(n.size() + 1, vector<vector<int64_t>>(2, vector<int64_t>(5)));
    DP[0][1][0] = 1;
    for (int i = 0; i < n.size(); i++){
        for (int j = 0; j < 4; j++){
            if (n[i] != '0'){
                DP[i + 1][1][j + 1] += DP[i][1][j];
                DP[i + 1][0][j] += DP[i][1][j];
                DP[i + 1][0][j + 1] += (n[i] - '0' - 1) * DP[i][1][j];
            } else {
                DP[i + 1][1][j] += DP[i][1][j];
            }
            DP[i + 1][0][j] += DP[i][0][j];
            DP[i + 1][0][j + 1] += 9 * DP[i][0][j];
        }
    }
    cout << DP[n.size()][1][k] + DP[n.size()][0][k] << endl;
}