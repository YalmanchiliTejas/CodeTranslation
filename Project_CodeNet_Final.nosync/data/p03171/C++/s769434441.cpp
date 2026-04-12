#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
ull sum=0;
ll dp[2][3001][3001];
int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
        sum+=arr[i];
        dp[0][i][i]=arr[i];
        dp[1][i][i]=0;
    }
    for(int l=2;l<=n;++l)
    {
        for(int i=1;i<=n-l+1;++i)
        {
           // dp[0][i][i+l-1] = max(dp[0][i][i+l-1],max());
           // dp[1][i][i+l-1] = max(dp[1][i][i+l-1],min(arr[i] + dp[0][i+1][i+l-1], arr[i+l-1] + dp[0][i][i+l-2] ));
           //if(i==2 && l==2)
          //  cout<<arr[i]+ dp[1][i+1][i+l-1]<<" "<<arr[i+l-1]+ dp[1][i][i+l-2]<<endl;
            if(arr[i]+ dp[1][i+1][i+l-1]>arr[i+l-1]+ dp[1][i][i+l-2])
            {
                dp[0][i][i+l-1] = arr[i]+ dp[1][i+1][i+l-1];
                dp[1][i][i+l-1] = dp[0][i+1][i+l-1];

            }
            else
            {
               
                dp[0][i][i+l-1] =  arr[i+l-1]+ dp[1][i][i+l-2];
                dp[1][i][i+l-1] = dp[0][i][i+l-2];
                // if(i==2 && l==2)
              //  cout<<"OK"<< dp[0][i][i+l-1] <<" "<<  dp[1][i][i+l-1]<<endl;
            }
            
        }
    }
  
    cout<<dp[0][1][n]-dp[1][1][n];

}