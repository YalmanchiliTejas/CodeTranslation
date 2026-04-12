#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;

int main(){
    string K; int D;
    cin>>K>>D;
    // ll dp[100010][100][2];//dp[keta][%D][smaller]
    vector<vector<vector<ll>>> dp(100010,vector<vector<ll>>(100,vector<ll>(2,0)));
    int L = K.size();
    //DP初期化
    dp[0][0][1] = 0;
    dp[0][0][0] = 1;
    vector<int> k;
    rep(i,L)k.push_back((int)(K[i]-'0'));
    //桁DPは配るDPで書いた方がわかりやすい。
    rep(keta,L){
        rep(mod,D){
            rep(digit,10){
                dp[keta+1][(mod+digit)%D][1] = (dp[keta+1][(mod+digit)%D][1] + dp[keta][mod][1]%MOD)%MOD;
            }
            rep(digit,k[keta]){
                dp[keta+1][(mod+digit)%D][1] = (dp[keta+1][(mod+digit)%D][1] + dp[keta][mod][0]%MOD)%MOD;
            }
            dp[keta+1][(mod+k[keta])%D][0] = (dp[keta+1][(mod+k[keta])%D][0] + dp[keta][mod][0]%MOD)%MOD;                
        }
    }
    cout<<(dp[L][0][1]+dp[L][0][0]-1+MOD)%MOD<<endl;
}
