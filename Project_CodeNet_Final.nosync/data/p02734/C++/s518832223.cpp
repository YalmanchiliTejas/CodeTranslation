#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const long long mo = 998244353;
const int maxi = 5000;
int a[maxi];
int s, n;
long long dp[maxi][maxi];
int main()
{

   cin>>n>>s;

   for (int i=1;i<=n;i++)
    cin>>a[i];


   long long ans = 0;

    dp[n+1][0] = 1;

   for (int i = n ;i>0;i--){

    for (int j = a[i];j<=s;j++)
        dp[i][j] = dp[i+1][j-a[i]];

       ans+=1ll*i*dp[i][s];
       ans%=mo;

       dp[i][0] = 1;

       for (int j = 0; j<=s; j++)
        dp[i][j] = (dp[i][j] + dp[i+1][j])%mo;
    }

    cout<<ans<<endl;
    return 0;
}
//volim tvoje oci tamne kao greh
