#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int b = 1;b <= n;++b) {
		int p = n / b;
		int r = n % b;
		ans += p * max(0, b - k) + max(0, r - k + 1);
		if (k == 0)--ans;
	}
	cout << ans << endl;
}