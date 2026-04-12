#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string K;ll D;
    cin>>K>>D;
    vector<vector<vector<ll>>> dp(10010/*i桁目まで見ている*/,vector<vector<ll>>(105/*余り*/,vector<ll>(2,0)/*smaller?*/));
    dp[0][0][false]=1;

    for(ll i=0;i<K.size();i++){
        ll now=K[i]-'0';
        for(ll j=0;j<D;j++){
            //1つ前がsmaller
            for(ll k=0;k<=9;k++){    
                dp[i+1][(j+k)%D][true]+=dp[i][j][true];
                dp[i+1][(j+k)%D][true]%=mod;
            }

            //1つ前がsame 今smaller
            for(ll k=0;k<now;k++){    
                dp[i+1][(j+k)%D][true]+=dp[i][j][false];
                dp[i+1][(j+k)%D][true]%=mod;
            }

            //1つ前がsame 今same
            dp[i+1][(j+now)%D][false]+=dp[i][j][false];
            dp[i+1][(j+now)%D][false]%=mod;
        }
    }


    cout<<(dp[K.size()][0][true]+dp[K.size()][0][false]-1+mod)%mod<<endl;//0除く
    return 0;
}