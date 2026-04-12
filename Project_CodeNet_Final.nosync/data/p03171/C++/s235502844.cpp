#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define llinf LONG_LONG_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // std::cout << std::setprecision(10) << std::fixed;
    ll int n,i,j;
    cin>>n;
    ll int a[n+1];
    ll dp[n+1][n+1];
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n-i+1);j++)
        {
            ll int l=j,r=j+i-1;
            if(l==r)
                dp[l][r]=a[l];
            else
                dp[l][r]=max((a[l]-dp[l+1][r]),(a[r]-dp[l][r-1]));
        }
    }
    cout<<dp[1][n];
}