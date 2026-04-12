// This is the start of  template//
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define ll int 
#define vll vector<int>
#define pb push_back
#define pll pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
void input(){
#ifndef ONLINE_JUDGE 
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout); 
#endif
}
#define INF LONG_LONG_MAX
#define mod 1000000007
#define array(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define cases int t; cin>>t; while(t--)
#define printall(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
ll power(ll a,ll n)
{
	if(n==0)
		return 1;
	if(n%2)
	{
		return (a*power((a*a)%mod,n/2))%mod;
	}
	return power((a*a)%mod,n/2);
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
// input();
  int n,total = 0 ,total2 = 0 ,final = 0; 
  cin>>n;
  array(a,n);
  for(int i = 0 ;i<n ;i++)
  {
  	total += a[i];
  	total %= mod;

  	total2 += power(a[i],2);
  	total2 %= mod;
  }
  // cout<<total2<<" ";
  total2 = (power(total,2) - total2 + mod)%mod;

  final = (total2%mod*power(2,mod-2)%mod)%mod;
  cout<<final;

}

