#include<bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<ll, ll> PLL;
typedef pair<ll, pair<ll, ll>> PLLL;

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define mod 1000000007
#define test ll t;cin>>t;while(t--)

void solve()
{
	ll n;
	cin >> n;
	ll arr[n],sum[n]={0};
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=(sum[i-1]+arr[i]+mod)%mod;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{
		ans+=(sum[i]*arr[i+1]+mod)%mod;
	}
	cout << (ans+mod)%mod;


	return;
}

int main()
{
	flash;

	// test
	// {
	// 	solve();
	// }
	solve();

	return 0;
}
