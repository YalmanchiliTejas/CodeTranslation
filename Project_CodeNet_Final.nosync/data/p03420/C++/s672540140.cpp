#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;
ll ans = 0;

int main() {
	cin >> n >> k;

	for (int b = k+1; b <= n; b++) {
		int pull = n / b * k + (k - 1);

		if (n / b*b + k - 1 > n)pull -= n / b*b + (k - 1) - n;

		ans += n - pull;
	}


	if (k == 0)ans = n*n;
	cout << ans << endl;
}