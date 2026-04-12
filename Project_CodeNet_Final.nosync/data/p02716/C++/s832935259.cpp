#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int m;
    if(n%2==0){
        m=2;
    }
    else{
        m=3;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m,-INF));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        vector<ll> tmp(m,-INF);
        for(int j=0;j<m;j++){
            if(dp[i][j]==-INF){
                continue;
            }
            if((i+j)%2==0){
                chmax(tmp[j],dp[i][j]+a[i]);
            }
            else{
                chmax(tmp[j],dp[i][j]);
            }
            if(j<m-1){
                chmax(tmp[j+1],dp[i][j]);
            }
        }
        for(int j=0;j<m;j++){
            dp[i+1][j]=tmp[j];
        }
    }
    cout << dp[n][m-1] << endl;
}