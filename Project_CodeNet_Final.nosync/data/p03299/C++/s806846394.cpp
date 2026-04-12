        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 510000;
const int MOD =  1000000007;
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

     signed main(){
     int n;
     cin>>n;
     int h[n+1]={};
     for(int i=0;i<n;i++)cin>>h[i];
     int dp[n][n+1];
     dp[0][n]=modpow(2,h[0],MOD);
     for(int i=0;i<n;i++){
       if(h[i]<=h[0]){
         dp[0][i]=modpow(2,h[0]-h[i]+1,MOD);
       }else dp[0][i]=0;
     }
     for(int i=1;i<n;i++){
       if(h[i]>h[i-1]){
         for(int j=0;j<=n;j++){
           if(h[i]>=h[j]){
             if(h[j]>h[i-1]){
               dp[i][j]=(dp[i-1][i-1]*modpow(2,h[i]-h[j],MOD)%MOD)*2%MOD;
             }else dp[i][j]=(dp[i-1][j]*modpow(2,h[i]-h[i-1],MOD)%MOD+dp[i-1][i-1]*modpow(2,h[i]-h[i-1],MOD)%MOD)%MOD;
           }else dp[i][j]=0;
         }
       }else{
         for(int j=0;j<=n;j++){
           if(h[i]>=h[j]){
             dp[i][j]=(dp[i-1][j]+dp[i-1][i])%MOD;
           }else dp[i][j]=0;
         }
       }
     }
     cout<<dp[n-1][n]<<endl;
                  
}


        
