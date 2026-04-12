#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int n, h, b_h = 0, ans = 0;
	cin >> n;
	for (int t = 0; t < n; t++) {
		cin >> h;
		if (b_h <= h) {
			ans++;
			b_h = h;
		}
	}
	cout << ans << endl;
}