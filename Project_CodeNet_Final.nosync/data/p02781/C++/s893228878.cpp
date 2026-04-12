// AtCoder template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;

ll dp[101][4][2]; // dp[上からi桁][何個0以外があるか][ smaller ]
string n;
ll k;

void init(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    cin >> k;
    dp[0][0][0] = 1LL;
    rep(i,n.size()) dp[i+1][0][1] = 1LL;
}

void solve(){
    
    // 最大桁数の計算
    for(int i = 0; i < n.size(); ++i){
        rep(j,k){
            if(n[i] == '0'){ 
                dp[i+1][j+1][1] = dp[i][j][1]*9 + dp[i][j+1][1];
                dp[i+1][j+1][0] = dp[i][j+1][0];
            }else{
                dp[i+1][j+1][1] = dp[i][j][1]*9 + dp[i][j][0]*(n[i]-'0'-1) + dp[i][j+1][1] + dp[i][j+1][0];
                dp[i+1][j+1][0] = dp[i][j][0];
            }
        }
    }

    // 出力
    cout << dp[n.size()][k][0] + dp[n.size()][k][1] << endl;
}

int main(){
    init();
    solve();
}