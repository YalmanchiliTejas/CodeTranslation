#include<bits/stdc++.h>
#include<math.h>
#define N 100005
#define K 200005
#define MOD (int)1e9+7
#define ll long long int
using namespace std;
ll max(ll a,ll b)
{
    return a>b? a:b;
}
int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll dp[n+1][n+1];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int l=n-1;l>=0;l-- )
    {

        for(int r=l;r<n;r++)
        {
            if(l==r)
            {
                dp[l][r]=a[l];
            }
            else
            {
            dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}