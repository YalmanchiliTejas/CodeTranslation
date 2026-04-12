#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n + 1), p(n + 1);
	a[0] = 1;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
	
	long long ans = 0;
	for (int i = n; i >= 0; i--) {
		if (i == 0) {
			ans += 1;
			break;
		}

		if (k == 1) {
			break;
		}
		else if (k <= a[i - 1] + 1) {
			k--;
		}
		else if (k == a[i - 1] + 2) {
			ans += p[i - 1] + 1;
			break;
		}
		else if (k <= 2 * a[i - 1] + 2) {
			ans += p[i - 1] + 1;
			k -= a[i - 1] + 2;
		}
		else {
			ans += p[i];
			break;
		}
	}
	cout << ans << endl;

	return 0;
}