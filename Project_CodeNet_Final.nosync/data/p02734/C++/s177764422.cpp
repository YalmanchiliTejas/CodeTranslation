        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD =998244353;

     signed main(){
        int n,s,a,ans=0;
        cin>>n>>s;
        int dp[s+1]={};
         for(int i=1;i<=n;i++){
                 cin>>a;
                 for(int j=s;j>=a;j--)dp[j]=(dp[j]+dp[j-a])%MOD;
                 if(a<=s)dp[a]=(dp[a]+i)%MOD;
                 ans=(ans+dp[s])%MOD;
         }
         
         cout<<ans;

         
}

        
