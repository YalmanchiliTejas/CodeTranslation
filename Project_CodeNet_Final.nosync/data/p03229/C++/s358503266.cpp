#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
int main() {
	int n;
	cin >> n;
	
	vector<long long> a(n);
	
	for (auto &&e : a)
		cin >> e;
	
	sort(a.begin(), a.end());
	
	long long half = n / 2;
	long long result = 0;
	for (long long i = 0; i < half; ++i) {
		if (i - 1 < 0)
			result += a[n - 1 - i] - a[n - half - 1];
		else
			result += a[n - 1 - i] - a[i - 1];
		
		if (i == half - 1 && n % 2 == 0)
			break;
		
		result += a[n - 1 - i] - a[i];
	}
	
	if (n % 2 == 1) {
		sort(a.begin(), a.end(), greater<long long>{});
		long long count = 0;
		for (long long i = 0; i < half; ++i) {
			if (i - 1 < 0)
				count += a[n - half - 1] - a[n - 1 - i];
			else
				count += a[i - 1] - a[n - 1 - i];
		
			count += a[i] - a[n - 1 - i];
		}
		
		if (result < count)
			result = count;
	}

	cout << result << endl;
}