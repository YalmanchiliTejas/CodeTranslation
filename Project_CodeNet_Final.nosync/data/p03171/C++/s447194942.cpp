#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_s long
#define mod 1000000007
#define forn(i,start,lim) for(ll i=start;i<lim;i++)
#define forn_d(i,start,lim) for(ll i=start;i>=lim;i--)
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define debug1(a) cout<<"------\n"<<#a<<" = "<<a<<endl<<"------"<<endl
#define debug2(a,b) cout<<"--------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<endl<<"--------------"<<endl
#define debug3(a,b,c) cout<<"----------------------\n"<<#a<<" = "<<a<<" ; "<<#b<<" = "<<b<<" ; "<<#c<<" = "<<c<<endl<<"----------------------"<<endl
#define sz(a) (ll)(a.size())
#define debug4(a) cout<<"chu "<<a<<endl
#define endl "\n"

ll a[3005];

ll dp[3005][3005];

ll fn(ll s,ll e){
  if(s==e)
    return a[s];
  if(dp[s][e]!=-1)
    return dp[s][e];
  ll ans=max(a[s]-fn(s+1,e),a[e]-fn(s,e-1));
  dp[s][e]=ans;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  forn(i,0,n)
    cin>>a[i];
  memset(dp,-1,sizeof(dp));
  ll ans=fn(0,n-1);
  cout<<ans<<endl;
  return 0;
}
