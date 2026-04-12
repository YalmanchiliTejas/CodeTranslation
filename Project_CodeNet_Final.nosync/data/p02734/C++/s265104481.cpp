#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int dp[3001][3001];
signed main(){
    int n,s,a[3000];
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j!=s)
                dp[i][j]=dp[i-1][j];
            if(a[i-1]==j)
                (dp[i][j]+=i)%=mod;
            if(a[i-1]<j)
                (dp[i][j]+=dp[i-1][j-a[i-1]])%=mod;
            if(j==s)
                (ans+=dp[i][j]*(n-i+1))%=mod;
        }
    }
    cout<<ans<<endl;
}
