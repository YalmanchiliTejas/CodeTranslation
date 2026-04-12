#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, long long int>> X;
	for (int ii = 0; ii<N; ii++) {
		long long int x;
		cin >> x;
		X.push_back(make_pair(ii, x));
	}

	sort(X.begin(), X.end(), [](const auto& item1, const auto& item2){
		return item1.second < item2.second;
	});

	long long int median_low = X[N / 2 - 1].second;
	long long int median_high = X[N / 2].second;

	sort(X.begin(), X.end(), [](const auto& item1, const auto& item2) {
		return item1.first < item2.first;
	});

	for (auto& x : X) {
		if (x.second <= median_low) {
			cout << median_high << endl;
		}
		else {
			cout << median_low << endl;
		}
	}
}
