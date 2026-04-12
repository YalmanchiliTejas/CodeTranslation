#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <list>

using namespace std;



int main() {
	int a, b, c, x, y, sum = 0,mini = 1000000000;
	cin >> a >> b >> c >> x >> y;
	for (int i = 0; i <= max(x, y); i++) {
		sum = 0;
		if (x - i > 0) {
			sum += (x - i) * a;
		}
		if (y - i > 0) {
			sum += (y - i) * b;
		}
		sum += 2 * i * c;
		mini = min(mini, sum);
	}
	cout << mini << endl;

	return 0;
}