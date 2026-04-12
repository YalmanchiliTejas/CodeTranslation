#include <iostream>

using namespace std;

const int M = 1e9 + 7;

int n, a[200000];
long long ans, sum;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);

		sum += a[i];
		// sum %= M;
	}

	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		ans += (a[i] * (sum % M)) % M;
		ans %= M;
	}

	cout << ans << endl;
}
