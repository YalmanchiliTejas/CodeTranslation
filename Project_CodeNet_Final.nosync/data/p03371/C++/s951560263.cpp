#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FOR(i,a,b)	for (int i = (a); i < (b); i++)
#define REP(i,n)	FOR(i, 0, n)

int main()
{
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	int ans = 0x7F7F7F7F;

	int totalA = 0;
	int totalB = 0;
	int totalC = 0;
	if (a + b > c * 2)
	{
		int cnum = min(x, y);
		totalC = cnum * 2 * c;
		x -= cnum;
		y -= cnum;
	}

	if (a > c * 2)
	{
		totalC += x * 2 * c;
		x -= x;
		y -= x;
	}
	else
	{
		totalA = x * a;
		x -= x;
	}

	if (b > c * 2)
	{
		totalC += y * 2 * c;
		x -= y;
		y -= y;
	}
	else
	{
		totalB = y * b;
		y -= y;
	}
	cout << (totalA + totalB + totalC) << endl;

	return 0;
}
