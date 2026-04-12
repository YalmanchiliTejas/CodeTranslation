#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

const ll INF = 1e18;

ll dp[200001][4];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    //解説動画より
    //i個目まで見て、これまでj個余分なxをはさんだときのmax
    //偶数の時 j=0,1
    //奇数の時 j=0,1,2
    
    
    int k = 1 + n%2;
    
    rep(i,n+1)rep(j,k+1)dp[i][j]=-INF;
    dp[0][0]=0;
    
    rep(i,n){
        rep(j,k+1){
            //いま余分なxを足した場合
            dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j] );
            
            //いま余計なxを足さない場合、次のoxはi+jの偶奇のみできまる
            ll now = dp[i][j];
            if((i+j)%2==0) now += a[i];
            
            dp[i+1][j] = max( dp[i+1][j], now);
        }
    }
    
    cout << dp[n][k] << endl;
    return 0;
    
}