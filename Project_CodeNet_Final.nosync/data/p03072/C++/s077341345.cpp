#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<int> H(N);
	for (auto&i:H) {
		cin >> i;
	}

	int result = 0;
	int max = 0;
	for (auto&i : H) {
		if (max <= i) {
			max = i;
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}