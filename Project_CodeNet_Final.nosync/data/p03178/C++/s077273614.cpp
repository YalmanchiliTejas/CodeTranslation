# include <bits/stdc++.h>
using namespace std;
const int D = 105, N = 1e4 + 100, mod = 1e9 + 7;
long long dp[D][2][2], n, m, ans;
string s;
int main(){
    cin >> s >> n;m = s.size();
    dp[0][0][1] = 1;
    s = '0' + s;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){  
            for(int d = 0; d < 10; d++){
                int x = (j - d + 15 * n) % n;
                dp[j][1][0] += dp[x][0][0];
                if(d == s[i] - '0'){
                    dp[j][1][1] += dp[x][0][1];
                }
                if(d < s[i] - '0'){
                    dp[j][1][0] += dp[x][0][1];
                }
                if(dp[j][1][0] >= mod)dp[j][1][0] -= mod;
                if(dp[j][1][0] >= mod)dp[j][1][0] -= mod;
            }
        }
        for(int j = 0; j < n; j++){
            dp[j][0][0] = dp[j][1][0];
            dp[j][0][1] = dp[j][1][1];
            dp[j][1][0] = dp[j][1][1] = 0; 
        }
    }  
    cout << (dp[0][0][0] + dp[0][0][1] - 1 + mod) % mod << endl;
}