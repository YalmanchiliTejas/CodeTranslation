#include <iostream>

using namespace std;

int main () {
	int res_price = 0;
	int a_price, b_price, ab_price, x, y;
	std::cin >> a_price >> b_price >> ab_price >> x >> y;
	
	if((a_price + b_price) > (ab_price * 2)) {
		res_price = (ab_price * 2) * std::min(x, y);
		int alpha_num = std::max(x, y) - std::min(x, y);	
		if (x > y) {
			if ((a_price * alpha_num) > (ab_price * 2 * alpha_num))
				res_price += (ab_price * 2 * alpha_num);
			else
				res_price += a_price * alpha_num;
		}
		else if (y > x) {
			if ((b_price * alpha_num) > (ab_price * 2 * alpha_num))
				res_price += (ab_price * 2 * alpha_num);
			else			
				res_price += b_price * alpha_num;
		}
	}
	else {
		res_price = a_price * x + b_price * y;
	}
	
	printf("%d", res_price);
	
	return 0;
}