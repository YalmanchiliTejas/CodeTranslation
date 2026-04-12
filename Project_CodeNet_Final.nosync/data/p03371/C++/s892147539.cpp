#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int x = 0;
	int y = 0;
	int payments;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	
	if (a < c && b < c) {
		payments = a * x + b * y;
	}
	else {
		if (x == y) {
			payments = 2 * c * x;
		}
		else {
			if (x > y) {
				payments = 2 * c * y + a * (x - y);
				if (payments > 2 * c * x) {
					payments = 2 * c * x;
				}
				if (payments > a * x + b * y) {
					payments = a * x + b * y;
				}
			}
			else {
				payments = 2 * c * x + b * (y - x);
				if (payments > 2 * c * y) {
					payments = 2 * c * y;
				}
				if (payments > a * x + b * y) {
					payments = a * x + b * y;
				}
			} 
		}
	}
	
	printf("%d\n", payments);
	
	return 0;
}