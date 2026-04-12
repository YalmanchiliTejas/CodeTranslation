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
	for (int u = 0; u < 100; u++)
	{
		int a[5],b[5];
		int p = 0;

		for (int i = 0; i < 5; i++)
		{
			cin >> a[i] >> b[i];
			if (a[i] == 0 && b[i] == 0)
			{
				p++;
				break;
			}
		}
		if (p != 0)
		{
			break;
		}

		int gg = 0,ggg = 0;
		for (int i = 0; i < 5; i++)
		{
			if (a[i] + b[i] > gg)
			{
				gg = 0;
				gg = a[i] + b[i];
				ggg = 0;
				ggg = i;
			}
		}


		if (ggg == 0)
		{
			cout << 'A';
		}
		else if (ggg == 1)
		{
			cout << 'B';
		}
		else if (ggg == 2)
		{
			cout << 'C';
		}
		else if (ggg == 3)
		{
			cout << 'D';
		}
		else if (ggg == 4)
		{
			cout << 'E';
		}
		cout << " " << gg << endl;
	}
}

