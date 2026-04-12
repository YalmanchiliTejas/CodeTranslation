#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
// 默认a < c < b
int solution(int a, int b, int c, int x, int y) {
	int sum = 0;
	if (c + c - a - b < 0) {
		if (x < y) {
			sum = 2 * x*c;
			sum += (y - x)*b;
			return sum;
		}
		else {
			sum = 2 * y*c;
			sum += (x - y)*a;
			return sum;
		}
	}
	else {
		return a*x + y*b;
	}
}

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a <= c && b <= c) {
		cout << a*x + b*y;
		return 0;
	}
	if (a < c) {
		cout << solution(a, b, c, x, y);
		return 0;
	}
	if (b < c) {
		cout << solution(b, a, c, y, x);
		return 0;
	}
	//c最小
	if (x > y)
		if (c * 2 - a < 0)
			cout << x * 2 * c;
		else
			cout << y*c * 2 + (x - y)*a;
	else
		if (c * 2 - b < 0)
			cout << y * 2 * c;
		else
			cout << x*c*2 + (y - x)*b;
	return 0;
}

