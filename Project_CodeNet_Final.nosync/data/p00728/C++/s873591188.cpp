#include "bits/stdc++.h"
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		vector<int> score(n);

		for (int i = 0; i < n; i++) {
			cin >> score.at(i);
		}

		sort(score.begin(), score.end());

		int sum = 0;

		for (int i = 1; i < n - 1; i++) {
			sum += score.at(i);
		}

		cout << sum / (n - 2) << endl;
	}
}

