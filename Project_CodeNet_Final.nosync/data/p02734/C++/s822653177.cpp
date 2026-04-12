#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t=1;
    //cin>>t;
    for(long long q=0;q<t;q++){
        int n,s;
        cin>>n>>s;
        int a[n];
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        long long dp[n][s+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<s;j++)
                dp[i][j+1]=0;
            dp[i][0]=i+2;
        }
        long long ans=0;
        if(a[0]<=s)
            dp[0][a[0]]=1;
        if(s==a[0])
            ans=n;
        for(int i=1;i<n;i++){
            if(s-a[i]>=0)
                ans=(ans+dp[i-1][s-a[i]]*(n-i))%998244353;
            for(int j=1;j<=s;j++){
                dp[i][j]=dp[i-1][j];
                if(j-a[i]>=0){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%998244353;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
