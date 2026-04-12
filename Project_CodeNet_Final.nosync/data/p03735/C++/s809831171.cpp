#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
	int n;
	std::cin >> n;

	const int INF = (int)1e9 + 10;

	std::vector<long long> x(n), y(n);
	long long rmax = -INF;
	long long rmin = INF;
	long long bmax = -INF;
	long long bmin = INF;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
		if (x[i] > y[i]) {
			std::swap(x[i], y[i]);
		}
		rmax = std::max(rmax, y[i]);
		rmin = std::min(rmin, y[i]);
		bmax = std::max(bmax, x[i]);
		bmin = std::min(bmin, x[i]);
	}
	auto max = std::max_element(y.begin(), y.end()) - y.begin();
	auto min = std::min_element(x.begin(), x.end()) - x.begin();

	long long ans = (rmax - rmin) * (bmax - bmin);

	if (max == min) {
		std::cout << ans << std::endl;
		return 0;
	}

	long long R = rmax - bmin;

	bmax = std::max(x[max], y[min]);
	bmin = std::min(x[max], y[min]);
	if (max < min) {
		std::swap(min, max);
	}
	x.erase(x.begin() + max);
	y.erase(y.begin() + max);
	x.erase(x.begin() + min);
	y.erase(y.begin() + min);
	n -= 2;

	for (int i = 0; i < n; i++) {
		if (x[i] > bmax) {
			bmax = x[i];
		}
		if (y[i] < bmin) {
			bmin = y[i];
		}
	}
	std::vector<long long> X, Y;
	for (int i = 0; i < n; i++) {
		if (x[i] < bmin && bmax < y[i]) {
			X.push_back(x[i]);
			Y.push_back(y[i]);
		}
	}

	std::vector<std::pair<long long, long long>> XY(X.size());
	for (int i = 0; i < X.size(); i++) {
		XY[i] = std::make_pair(X[i], Y[i]);
	}
	std::sort(XY.begin(), XY.end());
	for (int i = 0; i < XY.size(); i++) {
		std::tie(X[i], Y[i]) = XY[i];
	}

	for (int i = 0; i < X.size(); i++) {
		ans = std::min(ans, R * (bmax - X[i]));
		bmax = std::max(bmax, Y[i]);
	}
	ans = std::min(ans, R * (bmax - bmin));
	std::cout << ans << std::endl;
}