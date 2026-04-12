// ABC067_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	if ((r * 100 + g * 10 + b) % 4 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}

