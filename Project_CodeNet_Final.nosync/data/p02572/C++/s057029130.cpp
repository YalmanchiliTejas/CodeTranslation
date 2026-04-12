/////////////////////////////////TEST CASES////////////////////////////////////
/*
*/
/////////////////////////////////////CODE//////////////////////////////////////		
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define vl vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define FR(i,a) for(auto i:a)
#define what(A) cout<<#A<<" is "<<A<<endl;
ll MAX = 100000000000;
ll MOD = 1000000007;
void solve()
{
	IN(n);
	vl v;
	FOR(i, 0, n)
	{
		IN(in);
		v.push_back(in);
	}
	ll a=0;
	vl sum;
	FORD(i, n - 1, -1)
	{
		a =(a+ v[i])%MOD;
		sum.pb(a);
		//what(a);
	}
	reverse(all(sum));
	ll ans = 0;
	FOR(i, 0, n-1)
	{
		ans = (ans + sum[i+1] * v[i]) % MOD;
	}
	cout << ans << endl;

}
int main()
{
	fastio
		//freopen("input.txt", "rt", stdin);
		//freopen("output.txt", "wt", stdout);
		ll test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}