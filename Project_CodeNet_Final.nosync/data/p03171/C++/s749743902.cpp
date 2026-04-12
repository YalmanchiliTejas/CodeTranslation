#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.1415926535

ll dp[3005][3005];

int main() 
{
    FAST;
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n%2==0)
        for(int i=0;i<n;i++)
            dp[i][i]=-a[i];
    else
        for(int i=0;i<n;i++)
            dp[i][i]=a[i];
    for(int i=1;i<n;i++)
    {
        if((i+1+n)%2==0)
            for(int j=0,k=i;j<n && k<n;j++,k++)
                dp[j][k]=max(dp[j+1][k]+a[j],dp[j][k-1]+a[k]);
        else
            for(int j=0,k=i;j<n && k<n;j++,k++)
                dp[j][k]=min(dp[j+1][k]-a[j],dp[j][k-1]-a[k]);
    }
    cout<<dp[0][n-1];
    return 0;
}