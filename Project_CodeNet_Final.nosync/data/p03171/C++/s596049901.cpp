#pragma GCC optimize("O3")
//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  double
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define warmup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 3003, mod=1e9+7;
const ll inf=(1e9+11);
ll dp[N][N];

signed main()
{
    warmup

    int n;
    cin>>n;
    int a[n+1],i,j,l,r;
    ll sum=0;
    for(i=1;i<=n;++i)
        cin>>a[i],sum+=a[i];

    for(l=n;l>=1;--l)
    {
        dp[l][l]=a[l];
        for(r=l+1;r<=n;++r)
        {
            if(r-l==1)
                dp[l][r]=max(a[l],a[r]);
            else
                dp[l][r]=max(a[l]+min(dp[l+2][r],dp[l+1][r-1]),a[r]+min(dp[l+1][r-1],dp[l][r-2]));
        }
    }
    cout<<2*dp[1][n]-sum;

    return 0;
}
