#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int n, sum, avg;
		cin >> n;
		if (n == 0) {
			break;
		}

		sum = 0;
		int max_score = -1, min_score = 1001;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			min_score = min(min_score, tmp);
			max_score = max(max_score, tmp);
			sum += tmp;
		}
		sum -= min_score + max_score;
		avg = sum / (n - 2);
		cout << avg << endl;
	}

	return 0;
}