// template.cpp

// Defines.
//#define DEBUG
#define NUMBER_OF_DIGITS 6

// Includes.
#include <bits/stdc++.h>

#ifdef DEBUG
#include <chrono>
#endif

// Usings.
using namespace std;

// Main function.
int main()
{
#ifdef DEBUG
	chrono::system_clock::time_point start, end;
	
	start = chrono::system_clock::now();
#endif
	
	// settings.
	ios::sync_with_stdio(false);
	
	//cout << fixed;
	//cout << setprecision(NUMBER_OF_DIGITS);
	
	// logic.
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int total = 0;
	if ((a + b) >= (2 * c))
	{
		total += (min(x, y) * 2 * c);
		if (x >= y)
		{
			if (a >= (2 * c))
			{
				total += (x - y) * 2 * c;
			}
			else
			{
				total += (x - y) * a;
			}
		}
		else
		{
			if (b >= (2 * c))
			{
				total += (y - x) * 2 * c;
			}
			else
			{
				total += (y -x) * b;
			}
		}
	}
	else
	{
		total += (a * x);
		total += (b * y);
	}
	
	cout << total << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
