#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define fr(i,n) for(ll i=0;i<n;i++)
#define pii pair <ll ,ll>
#define ppi pair < pii , int > 
#define x first
#define y second

#include <bits/stdc++.h> 
int main()
{
    ll n;cin>>n;
    ll a[n];fr(i,n)cin>>a[i];
    ll dp1[n][n];
    ll dp2[n][n];
    fr(i,n)dp1[i][i]=a[i];
    fr(i,n)dp2[i][i]=0;
    for(ll l=1;l<n;l++)
    {
        fr(k,n-l)
        {
            ll i = k;
            ll j = k + l;
            // cout<<i<<" "<<j<<endl;
            ll c = a[i] + dp2[i+1][j];
            ll d = a[j] + dp2[i][j-1];
            dp1[i][j] = max(c,d);
            if(c>=d)dp2[i][j]=dp1[i+1][j];
            else dp2[i][j] = dp1[i][j-1];
        }
    }
    cout<<dp1[0][n-1] - dp2[0][n-1]<<endl;
    return 0;
}