#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int mod=1e9+7;
const int INF =LONG_LONG_MAX;
inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int pow(int a,int n,int mod){if(n==0)return 1;int p=pow(a,n/2,mod);p=(p%mod*p%mod)%mod;if(n%2) return (p%mod*a%mod)%mod;else return p;}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    int a[n];
   int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];s+=a[i];}
    int dp[n][n];
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;
            //cout<<i<<" "<<j<<endl;
           if(len==1)
           {
               dp[i][j]=a[i];continue;
           }
           if(len==2){dp[i][j]=max(a[i],a[j]);continue;}

           dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

   cout<<dp[0][n-1]-(s-dp[0][n-1])<<endl;
    return 0;
}
