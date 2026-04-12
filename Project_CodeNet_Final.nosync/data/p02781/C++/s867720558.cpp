#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[102][2][4];

int main()
{
    string n;
    cin >> n;
    int k;
    cin >> k;
    int l = n.size();
    reverse(n.begin(), n.end());
    dp[0][0][0] = 1;
    for(int i = 1; i <= l; i++){
        for(int j = 0; j <= k; j++){
            if(n[i - 1] == '0'){
                dp[i][0][j] += dp[i - 1][0][j];
                dp[i][1][j] += dp[i - 1][1][j];
            }
            else{
                dp[i][0][j] += dp[i - 1][0][j] + dp[i - 1][1][j];
            }
        }
        for(int j = 1; j <= k; j++){
            if(n[i - 1] == '0') dp[i][1][j] += (dp[i - 1][0][j - 1] + dp[i - 1][1][j - 1]) * 9;
            else{
                dp[i][0][j] += dp[i - 1][0][j - 1] * (n[i - 1] - '0') + dp[i - 1][1][j - 1] * (n[i - 1] - '0' - 1);
                dp[i][1][j] += dp[i - 1][0][j - 1] * (9 - (n[i - 1] - '0')) + dp[i - 1][1][j - 1] * (10 - (n[i - 1] - '0'));
            }
        }
    }
    cout << dp[l][0][k] << endl;
}