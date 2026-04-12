#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c, x, y, sum = 0;
	cin >> a >> b >> c >> x >> y;
	if (x > y) {
		swap(x, y);
		swap(a, b);
	}
	if (c * 2 > (a + b)) {
		sum += (a + b)*x;
	}
	else {
		sum += 2 * c*x;
	}
	y -= x;
	if (2*c > b) {
		sum += b*y;
	}
	else {
		sum += 2 * c*y;
	}
	cout << sum;
	return 0;
}