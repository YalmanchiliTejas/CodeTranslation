#include <iostream>
#include <iostream>
#include <boost/foreach.hpp>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	double x, y, z;
	cin >> x >> y >> z;
	cout << int((x - z) / (y + z)) << endl;
	return 0;
}