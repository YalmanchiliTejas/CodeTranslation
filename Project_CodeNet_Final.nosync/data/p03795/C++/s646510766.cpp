#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	int n, a, b;
	cin >> n;
	a = 800 * n;
	a -= (n / 15) * 200;
	cout << a << endl;
	return 0;
}