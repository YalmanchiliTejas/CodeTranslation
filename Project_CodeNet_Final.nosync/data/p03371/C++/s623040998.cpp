#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using namespace std;
int a[105];
int main() {
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long res;
	if (x > y) {
		res = min((a*x + b*y), (a*(x - y) + 2 * y*c));
		res = min((2 * x*c), res);
	}
	else {
		res = min((a*x + b*y), (b*( y-x) + 2 * x*c));
		res = min((2 * y*c), res);
	}
	cout << res << endl;
	return 0;
}