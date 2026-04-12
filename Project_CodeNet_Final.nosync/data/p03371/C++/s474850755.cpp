#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
#include <bitset>
#include <memory>
using namespace std;
typedef long long LL;
//#define _USE_MATH_DEFINES

int main(void) {
	LL a, b, c, x, y, i = 1000000000000, j = 1000000000000, k = 1000000000000, l = 1000000000000, m = 1000000000000, x2, y2, n = 1000000000000;
	cin >> a >> b >> c >> x >> y;
	x2 = x; y2 = y;

	if (a > b) {
		i = ((2 * x)*c);
		if (y > x) {
			i += (y-x)*b;
		}
	} else {
		j = ((2 * y)*c);
		if (x > y) {
			j += (x-y)*a;
		}
	}

	k = (x2*a) + (y2*b);


	if (x2 < y2) {
		l = ((2 * x2)*c);
		l += (y2 - x2)*b;
	} else {
		m = ((2 * y2)*c);
		m += (x2 - y2)*a;
	}

	n = (max(x2, y2) * 2)*c;

	cout << min(i, min(j, min(k, min(l, min(m, n))))) << endl;


	
	return 0;
}
