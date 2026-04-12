#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main (void)
{
	long long n,a,b,x;

	cin >> n >> a >> b;

	x = 0;

	for (long long i = 0; i < 100000; i++)
	{
		x = ((a + b) * i) + b;

		if (x == n)
		{
			cout << i << endl;
			break;
		}
		else if (x > n)
		{
			cout << i - 1 << endl;
			break;
		}
	}
}

