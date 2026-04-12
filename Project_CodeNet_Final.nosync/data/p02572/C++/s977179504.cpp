/***** author :  C0d1ngPhenomena *****/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define TestCases int T; cin>>T; while(T--)
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define revrep(i,a,b) for(ll i = b-1; i >= a; i--)
#define vll vector<ll>
#define vvll vector < vll >
#define pll pair<ll, ll>
#define vpll vector <pll>
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define alld(c) c.begin(),c.end(),greater<int>()
#define mem(a,val) memset(a,val,sizeof(a))
#define f first
#define s second
#define pb push_back
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll sum = 0;
	vll A(n);
	rep(i, 0, n)
	cin >> A[i];
	ll dp[n + 1] = {0};

	// rep(i, 1, n)
	// {
	// 	dp[i] = dp[i - 1] + A[i - 1];
	// }


	// revrep(i, 1, n)
	// {
	// 	sum += (A[i]%mod  * dp[i]%mod) % mod;
	// }
	ll suffix_sum = A[n - 1] % mod;
	
	for (ll i = n - 2; i >= 0; i--)
	{

		sum += (suffix_sum % mod * A[i] % mod) % mod;
		sum = sum%mod;
		suffix_sum += A[i] % mod;
		suffix_sum = suffix_sum % mod;
	}

	cout << sum << endl;

	return 0;
}





