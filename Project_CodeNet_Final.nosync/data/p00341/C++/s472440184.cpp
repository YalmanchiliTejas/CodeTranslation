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
	int a[12];

	for (int i = 0; i < 12; i++)
	{
		cin >> a[i];
	}
	sort (a,a + 12);
	int ng = 0,p = 0;

	for (int j = 0; j < 3; j++)
	{
		for (int i = j + (3 * j); i < j + (3 * j) + 3; i++)
		{
			if (a[i] != a[i + 1])
			{
				ng += 1;
				p += 1;
				break;
			}
		}
		if (p == 1)
		{
			break;
		}
	}
	if (ng != 0)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
}
