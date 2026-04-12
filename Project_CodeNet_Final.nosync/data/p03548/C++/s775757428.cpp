#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   

using namespace std;


int main() {
    long long x, y, z;
	int ans = 0;

	cin >> x >> y >> z;

	for (int i = 1; i <= x; i++) {
		if (y * i + z * (i + 1) <= x) {
			ans = i;
		}
	}
	
	cout << ans << endl;
}