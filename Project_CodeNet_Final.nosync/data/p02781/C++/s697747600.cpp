#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    string S; cin >> S;
    int K; cin >> K;
    S = "0" + S;
    int lenS = S.length();
    int cnt[lenS] = {}; //i文字目までに0でない数が出現した回数
    ll dp[4][lenS];
    
    rep(i, 4) rep(j, lenS) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i = 1; i < lenS; i++){
        if(S[i] == '0') cnt[i] = cnt[i-1];
        else cnt[i] = cnt[i-1] + 1;
    }

    for(int c = 0; c < lenS-1; c++){
        for(int k = 0; k <= K; k++){
            if(k < 3){
                dp[k][c+1] += dp[k][c];
                if(c == 0 && k == 0) dp[k+1][c+1] = (S[c+1]-'0');
                else if(c > 0 && k == cnt[c]){
                    dp[k+1][c+1] += (dp[k][c]-1)*9 + (S[c+1]-'0');
                }
                else dp[k+1][c+1] += dp[k][c]*9;
            }
            else{
                dp[k][c+1] += dp[k][c];
            }
        }
    }
    cout << dp[K][lenS-1] << endl;
    return 0;
}