#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, temp;
	cin >> n;

	vector<int> h;
	int max = -1;
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (max <= temp) {
			result++;
		}

		if (max < temp) {
			max = temp;
		}
	}

	cout << result;
}