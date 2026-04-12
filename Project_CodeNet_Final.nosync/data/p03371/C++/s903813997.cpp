#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int flag_a = 0, flag_b = 0, flag_ab = 0;
	if (a + b > c * 2) 	flag_ab = 1;
	if (a > c * 2) 	flag_a = 1;
	if (b > c * 2) 	flag_b = 1;
	
	long long ans = 0;
	if (flag_ab == 1) {
		if (x > y) {
			ans += c * 2 * y;
			x -= y;
			if (flag_a == 1) {
				ans += c * 2 * x;
			}
			else {
				ans += a * x;
			}
		}
		else {
			ans += c * 2 * x;
			y -= x;
			if (flag_b == 1) {
				ans += c * 2 * y;
			}
			else {
				ans += b * y;
			}
		}
	}
	else {
		if (flag_a == 1) {
			ans = c * 2 * x + (b - c * 2) * y;
		}
		else if (flag_b == 1) {
			ans = (a - c * 2) * x + c * 2 * y;
		}
		else {
			ans = a * x + b * y;
		}
	}

	cout << ans << endl;

	return 0;
}
