#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#define endl "\n"
#define debug(x) cout << #x << " : " << x << endl;
#define debug2(x, y) cout << #x << " : " << x  << ", " << #y << " : " << y << endl;
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0);
typedef long long ll;
using namespace std;

#define mod 1000000007
int main()
{
	FASTIO

	ll n;
	cin >> n;

	vector <ll> v(n);
	vector <ll> suffSum(n);
	suffSum[n - 1] = 0;
	for(ll i = 0; i < n; i ++)
	{
		cin >> v[i];
	}	

	for(ll i = n - 1; i > 0; i --)
	{
		suffSum[i - 1] = suffSum[i] + v[i];
	}

	ll ans = 0;
	for(ll i = 0; i < n; i ++)
	{
		ans = (ans % mod + ((v[i] % mod) * (suffSum[i] % mod)) % mod) % mod;
	}

	cout << ans << endl;
}