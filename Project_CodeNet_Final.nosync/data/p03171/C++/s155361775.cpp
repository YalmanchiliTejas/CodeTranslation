/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  100005
ll dp[3005][3005];
ll a[3005];
ll fun(ll l,ll r)
{
    if(l>r)
      return 0;
    if(dp[l][r]!=-1)
      return dp[l][r];
    dp[l][r]=max(a[l]+min(fun(l+1,r-1),fun(l+2,r)),a[r]+min(fun(l+1,r-1),fun(l,r-2)));
  return dp[l][r];
}
void solve()
{
   ll n;
   cin>>n;
   ll sum=0;
   for(int i=1;i<=n;i++)
   {
    cin>>a[i];
    sum+=a[i];
   }
   memset(dp,-1,sizeof(dp));
   ll o=fun(1,n);
   cout<<2*o-sum;
   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}