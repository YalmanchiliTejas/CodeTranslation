#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod=1e9+7;
int main() {
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif*/
    //cout << std::fixed;
    // cout << std::setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; ll m; cin>>s>>m;
    int n=s.size();
    ll dp[n-1][m];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
        }
    }
    for(int r=1;r<=9;r++){
        dp[0][r%m]++;
    }
    for(int i=1;i<n-1;i++){
        for(int j=0;j<m;j++){
            for(int r=0;r<=9;r++){
                ll k=(j+r%m)%m;
                dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n-2;i++){
        ans=(ans+dp[i][0])%mod;
    }
    ll dp1[n][m][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<2;k++){
                dp1[i][j][k]=0;
            }
        }
    }
    for(int r=1;r<(int)s[0]-48;r++){
        dp1[0][r%m][0]++;
    }
    dp1[0][((int)(s[0]-48))%m][1]++;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){ 
            int r=0;
            for(;r<(s[i]-48);r++){
                ll k=( j+r%m )%m;
                dp1[i][k][0]=(dp1[i][k][0]+(dp1[i-1][j][0]+dp1[i-1][j][1])%mod )%mod;
            }
            for(;r<=9;r++){
                ll k=( j + r%m )%m;
                dp1[i][k][0]=(dp1[i][k][0]+dp1[i-1][j][0])%mod;
                if(r==(s[i]-48) )
                dp1[i][k][1]=(dp1[i][k][1]+dp1[i-1][j][1])%mod;
            }
        }
    }
    ans=(ans+(dp1[n-1][0][0]+dp1[n-1][0][1])%mod )%mod;
    cout<<ans;
}