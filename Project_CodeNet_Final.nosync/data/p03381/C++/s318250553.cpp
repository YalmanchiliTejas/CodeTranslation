#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> x, sorted_x;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int xx;
		cin >> xx;
		x.emplace_back(xx);
	}

	sorted_x = x;

	sort(sorted_x.begin(), sorted_x.end());

	for (int i = 0; i < n; ++i) {
		int l = sorted_x[x.size() / 2 - 1];
		int r = sorted_x[x.size() / 2];

		if (x[i] <= l) {
			cout << r << endl;
		} else {
			cout << l << endl;
		}
	}


	return 0;
}