#include<bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr int mo = 1e9+7;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string n;
    cin>>n;
    int k;
    cin>>k;
    int len = n.size();
    vector<vector<vector<ll>>> dp(len+1,vector<vector<ll>>(2,vector<ll>(k+2)));
    dp[0][0][0] = 1;
    for(int i=0;i<len;++i)for(int j=0;j<=1;++j)for(int w=0;w<=k;++w){
        int ma = j ? 9 : n[i] - '0';
        for(int cur = 0; cur <= ma ; cur++){
            dp[i+1][j || cur < ma][w + (cur != 0)] += dp[i][j][w];
        }
    }
    cout << dp[len][0][k] + dp[len][1][k] << endl;
    return 0;
}