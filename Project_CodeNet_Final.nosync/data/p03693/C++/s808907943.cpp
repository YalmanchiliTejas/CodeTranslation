#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <limits.h>
#include <map>
#include <numeric>

namespace test {
	std::string to_string (char val) {
		return std::string (1, val);
		// return std::string{val};
	}
	//if( str.find ("r") != string::npos)
}

using namespace std;
typedef long long int llint;

int main (void) {
	int r,g,b; cin >> r >> g >> b;
	int result = r * 100 + g * 10 + b;
	cout << (result % 4 == 0 ? "YES" : "NO" ) << endl;
	return 0;
}
