#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int r,g, b, c, d, ans;
	cin >> r >> g >> b;
	r *= 100;
	g *= 10;
	c = r + g + b;
	cout << (c % 4 == 0 ? "YES" : "NO") << endl;
	return 0;
}