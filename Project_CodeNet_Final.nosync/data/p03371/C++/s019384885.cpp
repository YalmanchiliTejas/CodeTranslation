#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main (void)
{
	long a,b,c,x,y;

	cin >> a >> b >> c >> x >> y;

	long g = 0,gg = 0;

	gg += (a * x) + (b * y);

	if (x <= y)
	{
		g += x * c * 2;
		g += (y - x) * b;
	}
	else if (x > y)
	{
		g += y * c * 2;
		g += (x - y) * a;
	}
	int p = 0;
	p += max(x,y) * c * 2;

	if (min(g,gg) <= p)
	{
		cout << min(g,gg) << endl;
	}
	else
	{
		cout << p << endl;
	}
}
