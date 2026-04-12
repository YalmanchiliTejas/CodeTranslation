#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
 int mod=1000000007;
 long long fast_exp(long long a,long long n,long long mod1)
    {
     
      if (n==0)return 1;
      else if (n==1)return a;
      if (n%2==0)return fast_exp((a*a)%mod1,n/2,mod1);
      else return (a*fast_exp((a*a)%mod1,n/2,mod1))%mod1;
    }
void solve()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int c=0;c<n;c++)
        cin >> arr[c];

    if (n%2==0)
        {
            long long dp[2*100001];
            dp[n-1]=arr[n-1];
            dp[n-2]=max(arr[n-1],arr[n-2]);
            for (int c=n-3;c>=0;c--)
                {
                    if (c%2==0)
                        dp[c]=max(arr[c]+dp[c+2],dp[c+1]);
                    else 
                        dp[c]=(arr[c]+dp[c+2]);

                }
                cout << dp[0] << endl;
        }
    else
    {
        long long dp[2*100001][2];
        dp[n-1][0]=arr[n-1];
            dp[n-2][0]=max(arr[n-1],arr[n-2]);
            for (int c=n-3;c>=0;c--)
                {
                    if (c%2==1)
                        dp[c][0]=max(arr[c]+dp[c+2][0],dp[c+1][0]);
                    else 
                        dp[c][0]=(arr[c]+dp[c+2][0]);

                }

            dp[n-1][1]=0;
            dp[n-2][1]=max(arr[n-1],arr[n-2]);
            for (int c=n-3;c>=0;c--)
                {
                    if (c%2==1)
                        dp[c][1]=dp[c][0];
                    else 
                        dp[c][1]=max(dp[c+1][1],arr[c]+dp[c+2][1]);
                }
            cout << dp[0][1] << endl;
            
    }
    
    
        

}
    


    
 

int main()
{
    fast_io;
    int t;
   // cin >> t;
t=1;
    for (int tt=1;tt<=t;tt++)
    {
       // cout << "Case #" << tt << ": " ;    
        solve();
        
 
    }
 
    
    return 0;
}
 
