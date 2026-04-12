#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> max;
	max.reserve(10000);
	max.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		if (a[i] <= max.back()) {
			max.push_back(a[i]);
		}
		else {
			for (int j = 0; j < max.size(); ++j) {
				if (max[j] < a[i]) {
					max[j] = a[i];
					break;
				}
			}
		}
	}

	cout << max.size() << endl;

	return 0;
}