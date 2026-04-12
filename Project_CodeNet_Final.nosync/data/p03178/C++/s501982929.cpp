#include <bits/stdc++.h>
using namespace std;

const uint64_t M = 1'000'000'007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout.precision(12);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    string s;
    int d;
    cin >> s;
    cin >> d;

    static uint64_t dp[10001][100][2];
    dp[0][0][1] = 1;

    for(size_t i=0;i<s.size();i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<=9;k++){
                if(k < s[i]-'0'){
                    dp[i+1][(j+k)%d][0] += dp[i][j][0] + dp[i][j][1];
                    dp[i+1][(j+k)%d][0] %= M;
                }else if(k == s[i]-'0'){
                    dp[i+1][(j+k)%d][0] += dp[i][j][0];
                    dp[i+1][(j+k)%d][0] %= M;
                    dp[i+1][(j+k)%d][1] += dp[i][j][1];
                    dp[i+1][(j+k)%d][1] %= M;
                }else{
                    dp[i+1][(j+k)%d][0] += dp[i][j][0];
                    dp[i+1][(j+k)%d][0] %= M;
                }
            }
        }
    }
    
    cout << (dp[s.size()][0][0] + dp[s.size()][0][1] - 1 + M) % M << endl;
    return 0;
}