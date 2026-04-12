#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

int main() {
	int i, j, k;
	int a, b, c, x, y;
	int sum = 0;
	int sa = 0;

	cin >> a >> b >> c >> x >> y;

	int minn, maxn;
	minn = min(x, y);
	maxn = max(x, y);
	int dai;
	if (maxn == x) {
		dai = a;
	}
	else {
		dai = b;
	}

	sa = maxn - minn;


	//for (; ;) {
		if (c * 2 < a + b) {
			sum = c * minn * 2;

			if (c * 2 < dai) {
				sum = sum + c * 2 * sa;
				cout  << sum << endl;

				getchar();
				getchar();
				return 0;
			}
			else {
				sum = sum + dai * sa;

				cout  << sum << endl;

				getchar();
				getchar();
				return 0;
			}

		}
		else {
			sum = sum + (a * x);
			sum = sum + (b * y);

			cout << sum << endl;

			getchar();
			getchar();
			return 0;
		}




	//}





	getchar();
	getchar();
	return 0;
}