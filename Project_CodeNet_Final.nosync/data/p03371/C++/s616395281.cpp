#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int sum = 0;
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if(a + b > 2 * c) {
		if(x <= y) {
			sum = x * c * 2;
			sum = sum + (y - x) * b;
		}
		else {
			sum = y * c * 2;
			sum = sum + (x - y) * a;
		}
		if(2*max(x, y)*c <= sum) sum = 2*max(x,y)*c;
	}
	else {
		sum = a * x + b * y;
	}
	cout << sum << endl;
}
		