#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <iomanip>

using namespace std;

int dp[105][2][5];

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    
    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int sm = 0; sm < 2; ++sm){
            for(int j = 0; j < k + 1; ++j){
                for(int x = 0; x <= (sm ? 9 : s[i]-'0'); ++x){
                    dp[i + 1][sm || x < (s[i]-'0')][j+(x>0)] += dp[i][sm][j];          
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k];
}