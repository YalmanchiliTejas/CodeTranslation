#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int ans = X/(Y+Z);
	if (X%(Y+Z)<Z) ans--;
	cout << ans << endl;
}