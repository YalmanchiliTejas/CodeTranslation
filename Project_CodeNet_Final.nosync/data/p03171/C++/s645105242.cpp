#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >>n;
    int arr[n];
    for(int &x:arr)
    cin >>x;
    
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(l==r)
            dp[l][r]=arr[l];
            else
            {
                dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
    
}