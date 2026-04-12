#include<iostream>
#include<vector>
using namespace std;
using ll=long long ;
int main()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ll dp[n][n];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j]=arr[i];
            }
            else 
            {
                dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1];
}