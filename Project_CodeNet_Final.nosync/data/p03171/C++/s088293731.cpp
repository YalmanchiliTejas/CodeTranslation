#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()

ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


ll n;cin>>n;

vl a(n+1);

for(int i=1;i<=n;i++)cin>>a[i];

  vvl dp(n+2,vl(n+1,0));

//dp[l][r]---all the cards from [l,r] have been distributed .

for(int l=n;l>=1;l--)
{
  for(int r=l;r<=n;r++)
  {
    dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
  }
}

cout<<dp[1][n]<<"\n";




return 0;

}
