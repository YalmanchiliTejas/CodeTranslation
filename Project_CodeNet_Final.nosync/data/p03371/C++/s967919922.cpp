#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <utility>

int main() {
	int a, b, c, x, y, sum_price;
	std::cin >> a >> b >> c >> x >> y;
	std::vector<std::pair<int, int>> vec;
	vec.push_back(std::make_pair(a, x));
	vec.push_back(std::make_pair(b, y));
	std::sort(vec.begin(), vec.end());
	int min_price = vec[0].first;
	int all_num = x + y;
	int all_price = a + b;
	if (c*2 <= min_price) {
		std::cout << c * 2 * ((x>y) ? x : y) << std::endl;
		return 0;
	}
	else if (c*2 <= vec[1].first) {
		sum_price = c*vec[1].second*2;
		if (vec[0].second > vec[1].second) {
			sum_price += (vec[0].first * (vec[0].second - vec[1].second));
		}
	}
	else if (a+b >= c*2) {
        auto min_num_pizza = (vec[0].second < vec[1].second) ? vec[0] : vec[1];
        sum_price = min_num_pizza.second * c * 2;
        if (min_num_pizza.second < (all_num-min_num_pizza.second)) {
            sum_price += ((all_price - min_num_pizza.first) * ((all_num-min_num_pizza.second)-min_num_pizza.second));
        }
    }
	else {
		sum_price = a*x + b * y;
	}
	std::cout << sum_price << std::endl;
	return 0;
	 
}
