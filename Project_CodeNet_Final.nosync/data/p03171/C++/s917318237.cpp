#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false)
#define ll long long
ll a[600000], vs[600000], dp[4000][4000], fs[500][500];
map<int,int>mp;
string s , s1;
ll f(ll l, ll r)
{
    ll i, j, n;
    if(l==r) return a[l];
    if(dp[l][r]!=-1e18) return dp[l][r];
    j = max(a[l]-f(l+1,r),a[r]-f(l,r-1));
    dp[l][r]=j; return j;
}
int main()
{
    IO;
    ll j=0, n, m, k, m1, m2, a1=0, a2=0, l  = 1, t=3, mn, cnt=0, mx=0, h=0, mod=1e8+7, i; int tc=0;
    //cin>>t;
    //while(t--){
        cin>>n;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++) dp[i][j]=-1e18;
        for(i = 1; i<=n; i++)
              cin>>a[i];

        j = f(1, n); cout<<j<<endl;

    //}
    return 0;
}

