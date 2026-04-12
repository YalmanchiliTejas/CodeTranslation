#include<bits/stdc++.h>
using namespace std;
#define max1 3005
#define siz 100000
#define mod 1000000007
#define inf 1e18+5
#define ll long long int
#define debug(x) cout<<#x<<" "<<x<<endl
#define jam(x) cout<<"Case #"<<x<<": "
typedef pair<ll,ll> pr;
ll dp[max1][max1][2];
ll n;
vector<ll> a(max1);
ll fun(ll l,ll r,ll x)
{
  //cout<<l<<" "<<r<<" "<<x<<endl;
  if(l>r)
  {
    return 0;
  }
  if(dp[l][r][x]!=inf)
  {
    return dp[l][r][x];
  }
  if(x==0)
  {
    ll cnt=(-1)*inf;
    cnt=max(cnt,fun(l+1,r,x^1)+a[l]);
    cnt=max(cnt,fun(l,r-1,x^1)+a[r]);
    return dp[l][r][x]=cnt;
  }
  ll cnt=inf;
  cnt=min(cnt,fun(l+1,r,x^1)-a[l]);
  cnt=min(cnt,fun(l,r-1,x^1)-a[r]);
  return dp[l][r][x]=cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  /*#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif*/
  cin>>n;
  //cout<<n<<endl;
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<n;j++)
    {
      dp[i][j][0]=dp[i][j][1]=inf;
    }
  }
  for(ll i=0;i<n;i++)
  {
    cin>>a[i];
    //cout<<a[i]<<endl;
  }
  //cout<<n<<endl;
  ll ans=fun(0,n-1,0);
  cout<<ans<<endl;
}