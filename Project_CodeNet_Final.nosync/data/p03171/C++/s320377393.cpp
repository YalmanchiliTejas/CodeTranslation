#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll int **dp=new ll int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new ll int[n+1]();
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }
    
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            
            if(i==j)
                dp[i][j]=arr[i-1];
            else
            {
                dp[i][j]=max(arr[i-1]-dp[i+1][j],arr[j-1]-dp[i][j-1]);
            }
       
            
        }
     
    }
    cout<<dp[1][n];
           
}
