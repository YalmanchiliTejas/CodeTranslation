#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define sii set <ll>
#define vi vector <ll>
#define popcount(x) __builtin_popcountll(x)
#define mii map <ll,ll>
#define vpi vector <pair <ll,ll> >
#define sz(c) (int)c.size()
#define fr first
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for(ll i=a ; i<n ; i++)
#define ld long double
#define rall(a) (a).rbegin(),(a).rend()
#define INF 1000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
 
 
ll power(ll b,ll e,ll m)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b%m,e/2,m)%m;
  return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b,e/2);
  return power(b*b,e/2);
}  
bool isPowerOfTwo(ll x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}


 // void solution(ll a[],ll n)
 // {
 // 	ll sum=0;
 // 	rep(i,0,n)
 // 	sum=(sum%MOD+a[i]%MOD)%MOD;

 // 	ll square = ((sum%MOD)*(sum%MOD))%MOD;

 // 	ll sum2=0;

 // 	rep(i,0,n)
 // 	{
 // 		// sum2=(((sum2%MOD)+((a[i]%MOD)*(a[i]%MOD))%MOD)%MOD;
 // 		sum2=(sum2%MOD + (a[i]%MOD * a[i]%MOD)%MOD)%MOD;
 // 	}

 // 	// cout<<square<<"\n";
 // 	// cout<<sum2<<"\n";

 // 	ll ans= (square%MOD - sum2%MOD+MOD)%MOD;

 // 	cout<<(ans%MOD)/2;
 // }



ll findProductSum(ll A[], ll n)
{
	ll sum = 0,result=0;
	for (ll i = 0; i < n; i++)
	sum = (sum%MOD + A[i]%MOD)%MOD;
	for(ll i=0;i<n;i++)
	{
	    sum=(sum%MOD-A[i]%MOD + MOD)%MOD;
	    result=(result %MOD+ (A[i]%MOD*sum%MOD)%MOD)%MOD;
	}
	return result;
}


void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n) cin>>a[i];
	cout<<findProductSum(a,n);
}


int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
  fastio
  int tt=1;
  // cin>>tt;
  while(tt--)
  {
    solve();
    cout<<"\n";
  }
  return 0;
}