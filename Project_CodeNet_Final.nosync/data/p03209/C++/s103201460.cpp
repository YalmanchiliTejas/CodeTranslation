#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;
typedef int64_t LL;

LL calc(int n, LL x) {
	vector<LL> level, pati;
	LL lastv = 1, lastp = 1;
	level.push_back(1);
	pati.push_back(1);
	for (int i = 1; i <= n; ++i) {
		level.push_back(3 + lastv * 2);
		pati.push_back(1 + lastp * 2);
		lastv = 3 + lastv * 2;
		lastp = 1 + lastp * 2;
	}
	LL sum = 0;
	for (int i = n; i >= 0; i--) {
		if (x == 0) {
			break;
		}
		else if (x == 1) {
			if (i == 0)
				sum++;
			break;
		}
		else if (x <= level[i] / 2) {
			x--;
		}
		else if (x <= (level[i] + 1) / 2) {
			sum++;
			if (i > 0)
				sum += pati[i - 1];
			break;
		}
		else if (x <= level[i] - 2) {
			sum += pati[i - 1] + 1;
			x -= level[i - 1] + 2;
		}
		else {
			sum += pati[i];
			break;
		}
	}
	return sum;
}

int main() {
	int n;
	LL x;
	cin >> n >> x;
	cout << calc(n, x) << endl;
	/*
	for (int x = 0; x <= 13; ++x) {
		LL sum = calc(n, x);
		cout << x << " " << sum << endl;
	}*/
	return 0;
}