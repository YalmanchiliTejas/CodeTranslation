#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;




int main(){
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	int total = 0;
	//ABの値段に応じて場合分け
	if (a + b <= 2*c) {
		total = a * x + b * y;
	}
	else if (a + b > 2 * c) {
		if (x >= y) {
			if (c * 2 * y + a * (x - y) > c * 2 * x) {
				total = c * 2 * x;
			}
			else {
				total = c * 2 * y + a * (x - y);
			}
		}
		else {
			if (c * 2 * x + b * (y - x) > c * 2 * y) {
				total = c * 2 * y;
			}
			else {
				total = c * 2 * x + b * (y - x);

			}
		}
	}
	cout << total << endl;

	return 0;
}