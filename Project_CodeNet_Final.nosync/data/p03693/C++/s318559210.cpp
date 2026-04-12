#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
using namespace std;
typedef long long longlong;
typedef long long LL;

int main(void) {
	LL r, g, b, ans;
	cin >> r >> g >> b;
	ans = (100 * r) + (10 * g) + b;
	if (ans % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}