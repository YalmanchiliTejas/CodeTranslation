#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
typedef long long ll;
int main() {
	ll a = 0, b = 0, c = 0, x = 0, y = 0;
	ll honraisum = 0, toku = 0;
	ll sum = 0;
	std::cin >> a >> b >> c >> x >> y;
	honraisum = a*x + b*y;
	toku = (a + b) - (c * 2);
	if (toku >= 0) {
		sum = honraisum - (toku * std::min(x, y));
		if (x < y) {
			if (b >= c * 2) {
				sum = sum - (b - c * 2) * (std::max(x, y) - std::min(x, y));
			}
			std::cout << sum << std::endl;
			return 0;
		}else{
			if (a >= c * 2) {
				sum = sum - (a - c * 2) * (std::max(x, y) - std::min(x, y));
			}
			std::cout << sum << std::endl;
			return 0;
		}
	}
	else {
		std::cout << honraisum << std::endl;
		return 0;
	}
}