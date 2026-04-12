#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
typedef long long int ll;
using namespace std;

int main (void)
{
	ll x, y, z;
	ll result = 0;

	cin >> x >> y >> z;

	result = x/(z+y);
	if (x % (z+y) < z) result--;

	cout << result << endl;
}