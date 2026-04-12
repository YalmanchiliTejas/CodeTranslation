#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;cin>>n;
    int l = n.size();
    int K;cin>>K;
    vector<vector<vector<ll>>> dp=vector<vector<vector<ll>>>(l+1,vector<vector<ll>>(2,vector<ll>(K+2,0)));
    //dp[i][j][k]:上からi桁目、上位が小さいかどうか、0以外が出た回数+1
    dp[0][0][1]=1;

    for(int i=0; i<l; i++){
        //for(int j=0; j<2; j++){
            for(int k=1; k<=K+1; k++){
                if(n[i]=='0'){
                    dp[i+1][1][k]=dp[i][1][k-1]*9+dp[i][1][k];
                    dp[i+1][0][k]=dp[i][0][k];
                }
                else{
                    dp[i+1][1][k]=dp[i][1][k-1]*9+dp[i][1][k]+dp[i][0][k-1]*(n[i]-'0'-1)+dp[i][0][k];
                    dp[i+1][0][k]=dp[i][0][k-1];
                }

            }
        //}
    }
    cout<<dp[l][0][K+1]+dp[l][1][K+1];

    return 0;
}