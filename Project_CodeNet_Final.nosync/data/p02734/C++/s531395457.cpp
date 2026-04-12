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
         int dp[s+1]={},ans=0;
         for(int i=0;i<n;i++){
                 for(int j=s;j>=a[i];j--)dp[j]=(dp[j]+dp[j-a[i]])%MOD;
                 if(a[i]<=s)dp[a[i]]=(dp[a[i]]+i+1)%MOD;
                 ans=(ans+dp[s])%MOD;
         }
         
         cout<<ans;

         
}

        
