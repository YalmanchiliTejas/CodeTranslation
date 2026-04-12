#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
ll mod=998244353;
int inf=1000000000;
ll INF=10000000000000000;
int main(){
    string s;
    cin >> s;
    int l=s.size();
    int d;
    cin >> d;
    ll dp[2][l+1][d];
    rep(i,2){
        rep(j,l+1){
            rep(k,d) dp[i][j][k]=0;
        }
    }
    int y=s.at(0)-'0';
    dp[1][0][y%d]=1;
    rep(i,y) dp[0][0][(i)%d]++;
    rep(i,l-1){
        int u=s.at(i+1)-'0';
        rep(j,10){
            rep(k,d) (dp[0][i+1][(k+j)%d]+=dp[0][i][k])%=MOD;
        }
        rep(k,d) (dp[1][i+1][(k+u)%d]+=dp[1][i][k])%=MOD;
        rep(j,u){
            rep(k,d) (dp[0][i+1][(k+j)%d]+=dp[1][i][k])%=MOD;
        }
    }
    // rep(j,l+1){
    //         rep(k,d) cout << dp[1][j][k];
    //         cout << endl;
    //     }
    cout << (dp[0][l-1][0]+dp[1][l-1][0]-1+MOD)%MOD << endl;
}