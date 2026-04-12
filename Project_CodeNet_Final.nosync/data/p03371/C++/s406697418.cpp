#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int money = 0;
	while(x > 0 || y > 0) {
		if (x > 0 && y > 0) {
			if (a + b <= c * 2) {
				money += a + b;
				x--, y--;
			}
			else {
				money += c * 2;
				x--, y--;
			}
		}
		else if (x == 0) {
			if (b <= c * 2) {
				money += b;
				y--;
			}
			else {
				money += c * 2;
				y--;
			}
		}
		else if (y == 0) {
			if (a <= c * 2) {
				money += a;
				x--;
			}
			else {
				money += c * 2;
				y--;
			}
		}
	}
	cout << money;
}