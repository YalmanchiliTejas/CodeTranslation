#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define deb(x) cout << #x << " " << x << endl;
#define debtwo(x,y) cout << #x << " " << x << ", " << #y << " " << y << endl;
#define mod 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll arr[n];
	ll backsum[n + 1];
	ll res = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	backsum[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		backsum[i] = (arr[i] + backsum[i + 1]) % mod;
	}

	for (int i = 0; i < n - 1; i++) {
		res += (arr[i] % mod * backsum[i + 1] % mod) % mod;
	}
	cout << res % mod;
}