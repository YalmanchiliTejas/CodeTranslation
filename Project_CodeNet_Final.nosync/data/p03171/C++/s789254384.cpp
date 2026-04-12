#include<bits/stdc++.h>
#define Mx 1000000000005 
#define ll long long  
#define pi 3.141592653
#define vi vector<ll>
#define Mo 1000000007
#define mp make_pair
#define M map<ll,ll>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define vii vector<pair<ll,ll> > 
#define fi first
#define se second
#define pb push_back
#define ld long double
#define fill(a,x) memset(a,x,sizeof(a))
using namespace std;
bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
  return a.second<b.second;
}
/*vi b=v;
   sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  ll t; cin>>t; fr(f,0,t){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 */
vector<vector<ll>> dp(3001,vector<ll>(30001,-1));
ll func(ll l,ll r,ll a[])
{
  if(l==r) return a[l];
  if(r-l==1) return max(a[l],a[r]);

  if(dp[l][r]!=-1) return dp[l][r];

  ll x=a[l]+min(func(l+1,r-1,a),func(l+2,r,a));
  ll y=a[r]+min(func(l,r-2,a),func(l+1,r-1,a));
  return dp[l][r]=max(x,y);
}
int main()
{
  ll n,sum=0; cin>>n;
  ll a[n];
  fr(i,0,n)
  {
    cin>>a[i];
    sum+=a[i];
  }

  cout<<2*func(0,n-1,a)-sum;
}
