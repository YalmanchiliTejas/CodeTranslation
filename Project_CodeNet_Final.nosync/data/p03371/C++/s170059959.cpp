#include <iostream>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int64_t price = 0;
	int64_t min_price;
	for(int i = 0; i <= max(x, y); i++) { // ABピザを2i枚買ったとき
		price += 2 * i * c; //2i枚の値段
		if(x > i) { //ABピザで足りなかった分
			price += (x - i) * a;
		}
		if(y > i) { //ABピザで足りなかった分
			price += (y - i) * b;
		}
		if(i == 0) {
			min_price = price;
		}
		else {
			min_price = (price < min_price) ? price : min_price;
		}
		price = 0;
	}
	cout << min_price << endl;
}