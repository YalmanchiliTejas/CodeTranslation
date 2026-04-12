#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>

using namespace std;


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >>y;
	int a_num = x;
	int b_num = y;
	int c_num = 0;
	while (true) {
		if (a_num * a + b_num * b + c_num * c > max(a_num - 1, 0) * a + max(b_num - 1, 0) * b + (c_num + 2) * c) {
			if (a_num > 0) a_num--;
			if (b_num > 0) b_num--;
			c_num+=2;
		}
		else {
			break;
		}
	}
	cout << a_num * a + b_num * b + c_num * c << endl;
	return 0;
}