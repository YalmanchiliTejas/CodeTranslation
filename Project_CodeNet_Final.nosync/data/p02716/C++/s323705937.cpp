#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   int arr[n+1]={0};
   for(int i=1;i<=n;i++)
   cin>>arr[i];
   ll l[n+1]={0}; 
   l[1]=arr[1];l[2]=arr[2];
   for(int i=3;i<=n;i++)
   l[i]=l[i-2]+arr[i];
   ll dp[n+1][2];
   for(int i=0;i<=n;i++)
   {
       dp[i][0]=0;
       dp[i][1]=0;
   }dp[1][0]=0;
   dp[2][0]=arr[1];
   dp[1][1]=arr[1];
   dp[2][1]=arr[2];
   dp[3][0]=max(arr[2],arr[1]);dp[3][1]=arr[3];  //-100  -10
   dp[4][0]=l[3];dp[4][1]=arr[4]+dp[3][0];          //-1010    -100
   for(int i=5;i<=n;i++)
   {
       
       if(i%2)
       {
           dp[i][1]=max(dp[i-2][1],dp[i-2][0]);
           dp[i][1]=max(dp[i][1],dp[i-3][1]);
           dp[i][1]=max(dp[i][1],dp[i-3][0]);
           dp[i][1]+=arr[i];
           dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
       }
       else
       {
           dp[i][1]=max(dp[i-2][1],dp[i-2][0]);
           dp[i][1]=max(dp[i][1],l[i-3]);
           dp[i][1]+=arr[i];
           dp[i][0]=l[i-1];
       }
       //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<i<<endl;
       
   }
   cout<<max(dp[n][1],dp[n][0])<<endl;
      
    return 0;
}
//make all values ll



