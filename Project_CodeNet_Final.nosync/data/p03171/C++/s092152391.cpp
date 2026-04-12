#include<bits/stdc++.h>
using namespace std;
long long int max(long long int a,long long int b)
{
    if(a>=b)
    return a;
    else
    return b;
    
}
long long int min(long long int a,long long int b)
{
    if(a>=b)
    return b;
    else
    return a;
    
}
int main()
{
    long long int n;
    cin>>n;
    vector<long long int> arr;
    for(long long int i =0;i<n;i++)
    {
        long long int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<vector<long long int> > dp(n,vector<long long int>(n,0));
    for(long long int l=1;l<=n;l++)
    {
        for(long long int i = 0;i<=n-l;i++)
        {   
            if(l==1)
             dp[i][i+l-1] = arr[i];
             else if(l==2)
              dp[i][i+l-1] = abs(arr[i]-arr[i+l-1]);
              else
             dp[i][i+l-1] = max(min(arr[i]-arr[i+1]+dp[i+2][i+l-1],arr[i]-arr[i+l-1]+dp[i+1][i+l-2]),min(arr[i+l-1]-arr[i]+dp[i+1][i+l-2],arr[i+l-1]-arr[i+l-2]+dp[i][i+l-3]));
        }
    }
  
       
           cout<<dp[0][n-1];
       
       
   
}