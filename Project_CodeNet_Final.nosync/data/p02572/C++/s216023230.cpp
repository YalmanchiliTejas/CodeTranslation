#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<functional>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define  DESC std::greater<int>() //sort 3rd arg




int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<ll> b(n + 1, 0);
	int mod = 1000000007;
	
	REP(i,n) {
		cin >> a[i];
		b[i + 1] = b[i] + a[i];
	}

	ll ans = 0;

	REP(i,n) {
		ll sum = (b[n] - b[i + 1]) % mod;
//		ll sum = b[i + 1];

		ans += a[i] * sum;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}

