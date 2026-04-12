#include <bits/stdc++.h>

typedef long long ll;
#define ALL(a) a, a+sizeof(a)/sizeof(a[0])
#define all(a) a.begin(),a.end()
#define MOD 1000000007
using namespace std;
ll gcd(ll n, ll m) {
	if (m == 0) return n;
	return gcd(m, n % m);
}
ll lcm(ll n, ll m) {return m / gcd(n, m) * n;}

int main(void) {
	ll n,Max=0;
	string ans = "yes";
	cin >> n;
	vector<ll> d(n);
	for (ll i = 0; i < n; i++)
		cin >> d[i];
	for (ll i = 0; i < n; i++) {
		Max = max(Max,i*10+d[i]);
		
		if (Max < 10 * (i+1))
			ans = "no";
	}
	Max = 0;
	for (ll i = n - 1; i >= 0; i--) {
		Max = max(Max, (n-i-1)*10+d[i]);
		if (Max < 10 * (n-i))
			ans = "no";
	}
	cout << ans << endl;
	return 0;
}
