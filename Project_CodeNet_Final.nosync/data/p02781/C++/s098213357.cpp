#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    int digit = (int)s.size();
    vector<vector<vector<ll>>> dp(digit+1,vector<vector<ll>>(k+2,vector<ll>(2,0)));

    dp[0][0][1] = 1;

    for(int i = 0;i <= digit - 1;i++){
        for(int j = 0;j <= k;j++){
           dp[i+1][min(k+1,j+1)][0] += (dp[i][j][0] * 9);
           dp[i+1][j][0] += dp[i][j][0];
           if(s[i] != '0'){
               dp[i+1][min(k+1,j+1)][0] += dp[i][j][1] * (s[i] - '0' - 1);
               dp[i+1][min(k+1,j+1)][1] += dp[i][j][1];
               dp[i+1][j][0] += dp[i][j][1];
           }
           else dp[i+1][j][1] = dp[i][j][1];
        }
    }
    cout << dp[digit][k][0] + dp[digit][k][1] << endl;
}
