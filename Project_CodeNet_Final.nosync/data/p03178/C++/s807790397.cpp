# include <bits/stdc++.h>
using namespace std;
const int D = 105, N = 1e4 + 100, mod = 1e9 + 7;
long long dp[N][D][2], n, m, ans;
string s;
int main(){
    cin >> s >> n;m = s.size();
    dp[0][0][1] = 1;
    s = '0' + s;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){  
            for(int d = 0; d < 10; d++){
                int x = (j - d + 15 * n) % n;
                dp[i][j][0] += dp[i - 1][x][0];
                if(d == s[i] - '0'){
                    dp[i][j][1] += dp[i - 1][x][1];
                }
                if(d < s[i] - '0'){
                    dp[i][j][0] += dp[i - 1][x][1];
                }
                dp[i][j][0] %= mod;
                dp[i][j][1] %= mod;
            }
        }
    }  
    cout << (dp[m][0][0] + dp[m][0][1] - 1 + mod) % mod << endl;
}