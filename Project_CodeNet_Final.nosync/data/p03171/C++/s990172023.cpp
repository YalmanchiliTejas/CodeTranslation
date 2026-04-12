#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define INT_MAX 999999999
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll s =0;
    for(ll i = 0; i< n; i++)
       {
            cin>>a[i];
            s+=a[i];
       } 
    ll dp[n][n];
    for(ll i =0; i< n; i++)
    {
        dp[i][i] = a[i];
    }
    for(ll L = 2; L<=n; L++)
    {
        for(ll i = 0; i< n-L+1; i++)
        {
            ll j = i+L-1;
            ll x = (i+2) <= j ? dp[i+2][j] : 0;
            ll y = (i+1) <= (j-1) ?  dp[i+1][j-1] : 0;
            ll z = i <= (j-2) ? dp[i][j-2] : 0;

            dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }
    ll yy = s - dp[0][n-1];
    cout<<dp[0][n-1] - yy<<endl;

}