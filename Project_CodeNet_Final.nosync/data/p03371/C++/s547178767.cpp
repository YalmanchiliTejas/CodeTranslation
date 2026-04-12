#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	auto price = min(x, y) * min(a + b, c * 2);
	if (x > y) {
		price += (x - y) * min(a, c * 2);
	}
	else {
		price += (y - x) * min(b, c * 2);
	}
	cout << price << endl;
	return 0;
}
