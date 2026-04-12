#include<iostream>
#include<algorithm>
#include<string>
#define F(n) for(int i=0;i<n;i++)
using namespace std;
int a, b, c, x, y;
long money[3];
int main() {
	cin >> a >> b >> c >> x >> y;
	money[0] = a * x + b * y;
	money[1] = c *2*max(x, y);
	money[2] = c * 2 * min(x, y);
	money[2] += x > y ?a * (x - y) : b * (y - x);
	sort(money, money + 3);
	cout << money[0] << endl;
}