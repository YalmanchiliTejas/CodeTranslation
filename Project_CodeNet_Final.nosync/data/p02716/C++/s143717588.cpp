#include<bits/stdc++.h>
#define ll long long
#define MAXN 55
#define mod 998244353
#define INF 0x3f3f3f3f
#define ld long double
using namespace std;
ll dp[3][200005];
ll a[200005];
int main(){
    ios::sync_with_stdio(false);
    #define int ll
    int n;
    cin>>n;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
    if(n%2==0){

        dp[0][1]=a[1];
        dp[0][2]=a[2];
        dp[0][3]=a[3]+a[1];

       for(int i=4;i<=n;i++){
            if(i%2==0){
                dp[0][i]=a[i]+max(dp[0][i-2],dp[0][i-3]);
            }
            else{
                dp[0][i]=a[i]+dp[0][i-2];
            }
       }
       int ans=max(dp[0][n],dp[0][n-1]);
       cout<<ans<<endl;
    }
    else{
        dp[0][1]=a[1];
        dp[0][2]=a[2];
        dp[1][3]=a[3]+a[1];
        dp[0][3]=a[3];
        dp[0][4]=a[4]+max(a[1],a[2]);


        for(int i=5;i<=n;i++){
            if(i%2==0)dp[0][i]=a[i]+max(dp[0][i-2],dp[1][i-3]);
            else dp[0][i]=a[i]+max(dp[0][i-2],dp[0][i-3]);
           // cout<<dp[0][i]<<' ';
            if(i%2==1&&i!=n){
                dp[1][i]=a[i]+dp[1][i-2];
              //  ans=max(ans,dp[1][i]);
           //     cout<<dp[1][i];
            }
          //  cout<<endl;
            //ans=max(ans,dp[0][i]);
        }
        int ans=max(dp[1][n-2],max(dp[0][n-1],dp[0][n]));
        cout<<ans<<endl;
    }

    return 0;
}
