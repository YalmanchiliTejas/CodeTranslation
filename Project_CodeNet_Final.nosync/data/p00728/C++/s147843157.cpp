#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	while (n != 0) {
		vector<int> point(n);
		for (int i = 0; i < n; i++) cin >> point[i];

		sort(point.begin(), point.end());
		int sum = 0;
		for (int i = 1; i < n - 1; i++) sum += point[i];

		cout << sum / (n - 2) << endl;

		cin >> n;
	}

	return 0;
}
