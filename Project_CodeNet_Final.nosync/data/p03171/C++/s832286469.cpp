#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846
const ll MAX = 3e3+10;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main()
{
    ll n,i,j,k,l,p,q,x,y;
    cin >> n;
    ll a[n+1];
    for(i=1;i<=n;i++)
        cin >> a[i];
    ll dp[n+1][n+1];
    for(i=n;i>=1;i--)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout << dp[1][n];
}