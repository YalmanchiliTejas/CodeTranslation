        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD =998244353;

     signed main(){
             cout << std::setprecision(15) ;
         int n,s;
         cin>>n>>s;
         int a[n];
         for(int i=0;i<n;i++)cin>>a[i];
         int dp[s+1][n];
         for(int i=0;i<=s;i++)dp[i][0]=0;
        if(a[0]<=s) dp[a[0]][0]=1;
        int ans=dp[s][0];
         for(int i=1;i<n;i++){
                 for(int j=0;j<=min(s,a[i]);j++)dp[j][i]=dp[j][i-1];
                 for(int j=a[i];j<=s;j++)dp[j][i]=(dp[j][i-1]+dp[j-a[i]][i-1])%MOD;

                
                 if(a[i]<=s)dp[a[i]][i]=(dp[a[i]][i]+i+1)%MOD;
                 ans=(ans+dp[s][i])%MOD;
         }
         
         cout<<ans;

         
}

        
