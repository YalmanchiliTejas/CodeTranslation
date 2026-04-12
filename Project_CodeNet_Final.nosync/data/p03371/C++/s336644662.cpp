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
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans1 = 2* c * max(x, y);
	int ans2;
	if (x>y) {
		ans2 = 2*c*y + a*(x-y);
	}
	else {
		ans2 = 2*c*x + b*(y-x);
	}
	int ans3 = x * a + y * b;
	cout << min(min(ans1, ans2), ans3) << endl;
}