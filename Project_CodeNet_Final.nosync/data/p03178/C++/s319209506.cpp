#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;	

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define nl cout<<"\n"
#define MOD(x) ((x%P)+P)%P
#define vec(v) loop(i,0,v.size()) cout<<v[i]<<" "; nl
const int N = 100005;
const ll P = 1000000007;
const double eps = 1e-6;

int main()
{
	fastio();

	string num;
	int d;
	cin>>num>>d;

	ll dp[d+1][2] = {};
	//dp[i][0] = mod i and loose;
	//dp[i][1] = mod i and tight;	

	dp[0][1] = 1;

	for(int i=0; i<num.size(); i++)
	{
		ll newdp[d+1][2] = {};
		int mx = num[i]-'0';
		for(int rem = 0; rem<d; rem++)
		{
			for(int add = 0; add<10; add++)
			{
				int next = (rem+add)%d;
				newdp[next][0] = MOD(newdp[next][0]+dp[rem][0]);
				if(add<mx)
					newdp[next][0] = MOD(newdp[next][0]+dp[rem][1]);
				else if(add==mx)
					newdp[next][1] = MOD(newdp[next][1]+dp[rem][1]);
			}
		}
		for(int i=0; i<d; i++)
		{
			dp[i][0] = newdp[i][0];
			dp[i][1] = newdp[i][1];
		}
	}
	cout<<MOD(dp[0][0]+dp[0][1]-1);
	//cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}