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
	
	// a + b >= 2c -> should buy c.
	
	int totalCost = 0;;
	if ((a + b) >= (2 * c))
	{
		totalCost += min(x, y) * c * 2;
		if (x > y)
		{
			totalCost += min((x - y) * a, (x - y) * c * 2);
		}
		else if (x < y)
		{
			totalCost += min((y - x) * b, (y - x) * c * 2);
		}
	}
	else
	{
		totalCost += ((a * x) + (b * y));
	}
	
	cout << totalCost << endl;
	
#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
