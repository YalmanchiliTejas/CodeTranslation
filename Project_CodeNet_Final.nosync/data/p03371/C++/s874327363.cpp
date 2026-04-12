#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
#include<bitset>
using namespace std;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int ans = a * x + b * y;
	for (int i = 0; i <= 100000; i++) {
		if (i * 2 * c + max(0, x - i) * a + max(0, y - i) * b < ans) {
			ans = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b;
		}
	}
	cout << ans << endl;
}