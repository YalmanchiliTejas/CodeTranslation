#include<bits/stdc++.h>
using namespace std;

long long dp[3005][3005];

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) dp[i][i] = 0;

    for (int len=1; len<=n; len++) {
        for (int i=0; i+len<=n; i++) {
            int j = i+len;

            if ((n-len)% 2 == 0){
                dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j-1]);
                //cout << "i:" << i << ", j:" << j << " ";
                //cout << "先攻：" << dp[i][j] << endl;
            }
            else{
                dp[i][j] = min(dp[i+1][j] - A[i], dp[i][j-1] - A[j-1]);
                //cout << "i:" << i << ", j:" << j << " ";
                //cout << "後攻" << dp[i][j] << endl;
            }
        }
    }

    cout << dp[0][n] << endl;
}
