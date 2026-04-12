#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>

#define INF 1010101010

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	if (n % 2 == 0) {
		vector<int> ans(n);
		for (int i = 0; i * 2 < n; i++) {
			ans[i * 2] = a[n / 2 + i];
			ans[i * 2 + 1] = a[i];
		}

		long long sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(ans[i] - ans[i - 1]);
		}
		cout << sum << endl;
	} else {
		vector<int> ans(n);
		ans[n - 1] = a[n / 2];
		for (int i = 0; i < n / 2; i++) {
			ans[i * 2] = a[n / 2 + i + 1];
			ans[i * 2 + 1] = a[i];
		}

		long long sum1 = 0, sum2 = 0;
		for (int i = 1; i < n; i++) {
			sum1 += abs(ans[i] - ans[i - 1]);
		}

		int tmp = ans[n - 1];
		for (int i = n - 1; i > 0; i--) {
			ans[i] = ans[i - 1];
		}
		ans[0] = tmp;

		for (int i = 1; i < n; i++) {
			sum2 += abs(ans[i] - ans[i - 1]);
		}
		
		cout << max(sum1, sum2) << endl;
	}

	return 0;
}