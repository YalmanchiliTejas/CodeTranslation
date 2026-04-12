#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	cout << x / (y + z) << endl;
	return 0;
}