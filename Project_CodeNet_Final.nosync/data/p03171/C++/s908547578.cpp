 

#include <bits/stdc++.h> 

#define ll long long
#define M 1000000007
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int n,m,a,b;
    cin>>n;
    int arr[n];
    ll dp[n][n]={0 };
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    a=0;b=n-1;m=0;long long sum=0;
    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {   
            if(i%2)
            {dp[j][j+i]=min(dp[j+1][j+i]-arr[j],dp[j][j+i-1]-arr[j+i]);}
            else
            {
                dp[j][j+i]=max(dp[j+1][j+i]+arr[j],dp[j][j+i-1]+arr[j+i]);
            }
            
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            cout<<dp[i][j]<<" ";
        }
    cout<<endl;
    }*/
    if(n%2)
    {
        cout<<dp[0][n-1];
    }else
    {
         cout<<dp[0][n-1]*-1;
    }
    
}