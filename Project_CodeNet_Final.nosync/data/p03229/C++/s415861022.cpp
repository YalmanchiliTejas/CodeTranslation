#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int n;

int main() {

	cin >> n;
	vector<long long> data(n);

	for (int i = 0; i < n; ++i)
		cin >> data[i];

	if (n == 2)
	{
		cout << abs(data[1] - data[0]) << endl;
		return 0;
	}

	sort(data.begin(), data.end(), greater<int>());

	long long ans = 0;
	if (n == 3)
	{
		ans = max(data[1] + data[0] - data[2] * 2,
				data[0] * 2 - data[1] - data[2]);
		cout << ans << endl;
		return 0;
	}

	if ((n&1) == 0)
	{
		int i = 0;
		for ( ; i < n/2 - 1; ++i)
			ans += data[i]*2;

		ans += data[i] - data[i+1];
		i += 2;
		for ( ; i < n; ++i)
			ans -= data[i]*2;

	} else {

		long long tmp = 0;
		int i = 0;
		for ( ; i < n/2 - 1; ++i)
			tmp += data[i]*2;

		tmp += data[i] + data[i+1];
		i += 2;
		for ( ; i < n; ++i)
			tmp -= data[i]*2;

		ans = tmp;
		tmp = 0;
		i = 0;
		for ( ; i < n/2; ++i)
			tmp += data[i]*2;

		tmp += - data[i] - data[i+1];
		i += 2;
		for ( ; i < n; ++i)
			tmp -= data[i]*2;

		// printf("tmp:%lld\n", tmp);
		ans = max(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}
