#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
	int n;
	int x, y;
	
	cin >> n;

	x = 800 * n;
	y = 200 * (n / 15);

	cout << x - y << endl;

	return (0);
}