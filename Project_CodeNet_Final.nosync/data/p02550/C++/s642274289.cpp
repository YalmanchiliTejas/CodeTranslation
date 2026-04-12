#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define testcase ll T; cin >> T; for (ll tc = 1; tc <= T; tc++)
#define M 1000000007
#define MM 998244353
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
#define r2 1.41421356237
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //testcase {
  ll n,x,m,gg;
  cin>>n>>x>>m;
  ll sa=0;
  ll c=1;
  set<ll>s;
  vector<ll>v;
  v.pb(0);
  v.pb(x);
  s.insert(x);
  for(int i=2;i<=n;i++) {
  	x=(x*x)%m;
  	if(s.count(x)) { break; }
  	else { c=i; v.pb(x); s.insert(x); }
  }
  for(int i=1;i<=n;i++) { if(v[i]==x) { gg=i; break; } }
  for(int i=0;i<gg;i++) { sa+=v[i]; }
  for(int i=gg;i<=c;i++) {
  	ll w=(n-i)/(c-gg+1);
  	sa+=(w+1)*v[i];
  }
  cout<<sa;
  //}
  return 0;
}
