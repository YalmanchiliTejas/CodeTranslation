#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<utility>
#include<iterator>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
//#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(a,n) for(ll i=a;i<n;i++)
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define sc second
#define fs first
#define c(a) cout<<a<<endl
const ll m=1000000007;
ll mod(ll a,ll b)
{
	a=a%m;
	b=b%m;
	return(a*b)%m;
}
ll modd(ll a)
{
	return a%m;
}
void solve()
{
	ll n; cin>>n; ll a[n];
	ff(0,n) cin>>a[i];
	ll ans=0;
	ll x=0;
	for(ll i=0;i<n;i++)
	{
		ans+=modd(mod(a[i],x));
		x=(modd(x)+modd(a[i]))%m;
	}
	ans=ans%m;
	cout<<ans;
}

int main()
{
	solve();
}
/*




*/
