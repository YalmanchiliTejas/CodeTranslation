#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;
	return 0;
}