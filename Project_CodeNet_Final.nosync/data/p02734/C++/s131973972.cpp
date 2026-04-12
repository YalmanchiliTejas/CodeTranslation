#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int mod=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,s;cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll dp[n+1][s+1][3]={};
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            (dp[i+1][j][0]+=dp[i][j][0])%=mod;
            (dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
            (dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=mod;
            if(j+a[i]<=s){
                (dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
                (dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1])%=mod;
            }
        }
    }
    cout << dp[n][s][2] << endl;
}