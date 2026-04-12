#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)	cin >> a[i];

	int ans = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + (long long)a[i] * x) % mod;
		x = (x + a[i]) % mod;
	}

	cout << ans << endl;
	return 0;
}