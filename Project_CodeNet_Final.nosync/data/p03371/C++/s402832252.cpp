#include<string>
using namespace std;
#include <stdio.h>
#include <limits.h>
#include "bits/stdc++.h"
int a, b, c, x, y, z, n, m, ans1;
int main() 
{
	cin >> a >> b >> c >> x >> y;
	if (c * 2 >= a + b) {
		ans1 = a*x + b*y;
}
	if (x >= y) {
		z = x;
		n = a;
		m = y;
	}
	if (x < y) {
		z = y;
		n = b;
		m = x;
	}
	if (c * 2 < a + b) {
		if (c < n / 2) {
			ans1 = z*c * 2;
		}
		else {
			ans1 = m*c * 2 + n*(z - m);
		}
	}
	cout << ans1;
	return 0;

}