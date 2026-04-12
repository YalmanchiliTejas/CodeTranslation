#include<iostream>
#include<vector>
#include <unordered_map>  
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <float.h>
using namespace std;

int main() {
	unsigned int a, b, c, x, y, sum = 0;
	cin >> a >> b >> c >> x >> y;
	if ((a + b) / 2 >= c) {
		while (x > 0 && y > 0) {
			--x; --y; sum += 2 * c;
		}
	}
	while (x > 0) {
		if (a > c * 2) {
			--x; --y; sum += c * 2;
		}else{
			--x; sum += a;
		}
	}
	while (y > 0) {
		if (b > c * 2) {
			--x; --y; sum += c * 2;
		}
		else {
			--y; sum += b;
		}
	}
	cout << sum << endl;
	return 0;
}