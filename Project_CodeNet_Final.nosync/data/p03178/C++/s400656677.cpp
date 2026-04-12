#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
ll mod = 1e9+7;
ll dp[2][110][10100]; //ギリギリ攻めてるか　あまり　すでに見た桁数

int main(){
    string s;
    cin >> s;
    int d;
    cin >> d;
    dp[1][0][0] = 1;
    rep(i,s.length()){
        rep(j,d){
            rep(k,10){
                if(k==s[i]-'0'){
                    dp[1][(j+k)%d][i+1] += dp[1][j][i];
                    dp[1][(j+k) % d][i + 1] %= mod;
                }
                if(k<s[i]-'0'){
                    dp[0][(j+k)%d][i+1] += dp[1][j][i];
                    dp[0][(j+k) % d][i + 1]%=mod;
                }
                dp[0][(j+ k) % d][i + 1]+=dp[0][j][i];
                dp[0][(j+ k) % d][i + 1] %= mod;
            }
        }
    }
    cout << (dp[1][0][s.length()]+dp[0][0][s.length()]-1+mod)%mod << endl;
    return 0;
}