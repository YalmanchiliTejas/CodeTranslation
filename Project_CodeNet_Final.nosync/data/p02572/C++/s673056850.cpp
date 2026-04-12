#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	ll mod = 1000000007;
	vector<ll> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i] % mod;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		sum = (sum - a[i] + mod) % mod;
		ans = (ans + (sum * a[i]) % mod) % mod;
	}

	cout << ans << '\n';


	

}