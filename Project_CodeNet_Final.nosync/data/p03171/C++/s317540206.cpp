/*There's a possibility*/
#define dbg(...) ; 
#define db(...) ; 
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define tst cout<<'*';
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mod 1000000007
using namespace std;

ll n, ar[3005], dp[3005][3005];

ll fun(int l, int r)
{
    if(l==r)
        return ar[l];
    if(dp[l][r]!=-1)
        return dp[l][r];
    return dp[l][r]=max(ar[l]-fun(l+1,r),ar[r]-fun(l,r-1));
}

int main()
{
    fast;
    int i;
    cin>>n;
    f(i,0,n)
        cin>>ar[i];
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1);
}