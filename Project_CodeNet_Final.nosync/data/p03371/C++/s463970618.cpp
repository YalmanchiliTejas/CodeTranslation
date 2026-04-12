#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int p, q, r;
	p = max(x, y) * 2 * c;
	q = a * x + b * y;
	if (x > y)r = y * 2 * c + (x - y)*a;
	else r = x * 2 * c + (y - x)*b;
	cout << min(p, min(q,r)) << endl;
}