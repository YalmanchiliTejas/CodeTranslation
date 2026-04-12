#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n;
    cin>>n;
    vector<long long> arr(n,0);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<long long>> dp(n,vector<long long>(n,0));
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(r==l)
             dp[l][r]=arr[l];
            else
             dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1];
return 0;
}
