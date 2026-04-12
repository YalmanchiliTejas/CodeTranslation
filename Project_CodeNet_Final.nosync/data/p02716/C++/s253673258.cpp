#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{


    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++)cin>>arr[i];


    int dp[n+1],odd[n+1];
    memset(odd,0,sizeof(odd));
    memset(dp,0,sizeof(dp));

    odd[1]=arr[1];

    //(1,3,5,7,9.....)
    for(int i=3;i<=n;i++){
        if(i%2==1)odd[i] = odd[i-2]+arr[i];
    }

    dp[0]=0;
    dp[1]=0;
    // n is odd
    // n is even  (1,3,5,7...) or (2,4,6,8...)
    for(int i=2;i<=n;i++)
    {
        if(i%2==0){
            dp[i] = max(odd[i-1],dp[i-2]+arr[i]);
        }
        else{
            dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
        }
    }
   // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
   cout<<dp[n];
}
