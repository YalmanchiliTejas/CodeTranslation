#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, 0)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = s[0] - '0' - 1;
    for(int i = 1; i < n; i++){
        dp[i][0][0] = 0;
        dp[i][0][1] = 1;
        for(int j = 1; j <= k; j++){
            if(s[i] == '0'){
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][1] * 9;
            }else{
                dp[i][j][0] = dp[i-1][j-1][0];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][0] + dp[i-1][j-1][1] * 9 + dp[i-1][j-1][0] * (s[i] - '0' - 1);
            }
        }
    }
    cout << dp[n-1][k][0] + dp[n-1][k][1] << endl;
}