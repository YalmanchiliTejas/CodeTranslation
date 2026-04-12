#include<iostream>
 
using namespace std;
 
int main() {
	int a, b, c, x, y,money=0;
 
	cin >> a >> b >> c >> x >> y;
 
	if (x > y) {
		if (a+b > c*2) {
			money += y * c * 2;
			x -= y;
		}
		else {
			money += y * b;
		}
		if (a > c*2) 
			money += x * c * 2;
		else
			money += x * a;
	}
	else {
		if (a+b > c*2) {
			money += x * c * 2;
			y -= x;
		}
		else {
			money += x * a;
		}
		if (b > c*2)
			money += y * c * 2;
		else
			money += y * b;
	}
 
	cout << money;
 
	return 0;
}