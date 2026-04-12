#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int sz=3003;
ll dp[sz][sz];
int main()
{

    memset(dp,0, sizeof dp);
    int n;
    cin>>n;
    int inp[n];
    for(int i=0;i<n;i++)
    {
        cin>>inp[i];
    }
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(r==l)
                dp[l][r]=inp[l];
            else
                dp[l][r]=max(inp[l]-dp[l+1][r],inp[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
