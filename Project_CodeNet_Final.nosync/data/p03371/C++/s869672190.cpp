#include<iostream>
using namespace std;

int main() {
	int pizza_A, pizza_B, pizza_AB, x, y,money=0;
	cin >> pizza_A >> pizza_B >> pizza_AB >> x >> y;

	int flag = 0,a,b;
	a = pizza_AB*2;
	b = pizza_A + pizza_B;
	
	if (a < b) {
		flag = 1;
	}

	if (flag) {
		if (x > y) {
			for (int i = y; i > 0; i--) {
				money = money + pizza_AB * 2;
			}
			if (pizza_AB * 2 * (x - y) > pizza_A*(x - y)) {
				money = money + pizza_A*(x - y);
			}
			else {
				money = money + pizza_AB * 2 * (x - y);
			}
		}
		if (x <= y) {
			for (int i = x; i > 0; i--) {
				money = money + pizza_AB * 2;
			}
			if (pizza_AB * 2 * (y - x) > pizza_B*(y - x)) {
				money = money + pizza_B*(y - x);
			}
			else {
				money = money + pizza_AB * 2 * (y - x);
			}
		}
	} else {
		money = pizza_A*x + pizza_B*y;
	}
	cout << money << endl;

	return 0;
}