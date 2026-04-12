// ABC067_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n * 800 - n / 15 * 200 << endl;
	return 0;
}

