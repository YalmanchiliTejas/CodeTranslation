#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll total = 0;
	ll result = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
		total %= mod;
	}

	for (int i = 0; i <n-1;i++) {
		total -= a[i];
		if (total <= 0) total += mod;
		result += total * a[i];
		result %= mod;
	}

	cout << result << endl;

	return 0;
}
