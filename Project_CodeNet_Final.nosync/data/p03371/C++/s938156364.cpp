#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
#include <iomanip>
using namespace std;
#define Would
#define you
const int INF = 999999999;
const int MOD = 1e9 + 7;

int main() {
	int a, b, c, d, e, ans = 0, re;
	cin >> a >> b >> c >> d >> e;
	re = d;
	int mon = min(d, e)*min(a + b, c * 2);
	d -= min(re, e); e -= min(re, e);
	mon += d * min(a, 2 * c) + e * min(b, c * 2);
	cout << mon << endl;
}
