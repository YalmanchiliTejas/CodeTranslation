                    //S.G.N.//
#include <bits/stdc++.h>
using namespace std;
typedef vector< long long > vi;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fr(n) for(ll i=0;i<n;i++)
#define tr(a) for(auto it=a.begin();it!=a.end();it++)
#define N 998244353445 
#define PI 3.1415926535897932384
#define F first
#define S second
#define mp make_pair
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007

void solve()
{
 ll n;
 cin>>n;
 ll a[n];
 fr(n)
 {
  cin>>a[i];
 }
 ll dp[n+1][n+1];
 ll flag=(n%2);
 fr(n+1)
 {
  if(i==0)
    continue;
  
    rep(j,0,n+1-i)
    {
      if(i==1){
        if(i%2==flag)
        dp[j][j+i-1]=a[j];
      else
        dp[j][j+i-1]=-a[j];
      }
      else{
        if(i%2==flag)
      dp[j][j+i-1]=max(dp[j+1][j+i-1]+a[j],dp[j][j+i-2]+a[j+i-1]);
    else
      dp[j][j+i-1]=min(dp[j+1][j+i-1]-a[j],dp[j][j+i-2]-a[j+i-1]);
    }
    //cout<<dp[j][j+i-1]<<" ";
    }
//cout<<endl;
  
 }
 cout<<dp[0][n-1];
}
int main()
{
  
  #ifndef ONLINE_JUDGE
     * freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
  FAST
  ll test;
test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
  return 0;
}