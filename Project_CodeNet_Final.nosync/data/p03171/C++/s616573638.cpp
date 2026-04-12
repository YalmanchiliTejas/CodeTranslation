#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
typedef long long int ll;
using namespace std;
#define P 1000000007
#define rep(i,n) for(i=0;i<n;++i)
#define repp(i,a,n) for(i=a;i<n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)

ll binpowmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return binpowmod(n, p-2, p);
}

ll calc(ll dp[],ll k,ll a[],ll n)
{
    if(k<a[1]) return -1;
    ll i;
    for(i=1;i<=n&&k>=a[i];++i)
    {
        if(dp[k-a[i]]==0) dp[k-a[i]]=calc(dp,k-a[i],a,n);
        if(dp[k-a[i]]==-1) return 1;
    }
    return -1;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,j,k;
    cin >> n ;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    repr(i,n-1,0)
    {
        repp(j,i,n)
        {
            if(i==j) dp[i][j]=a[i];
            else
            {
                dp[i][j]=std::max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] ;
    return 0;
}