#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 10e8;
const int MAX_V = 201;
void ISU() {
	int x, y, z;
	cin >> x >> y >> z;
	int pad = (x - 2 * z);
	int div = pad / (y + z);
	int rem = pad % (y + z);

	cout << (div + (rem >= y)) << endl;
}

int main() {
	ISU();
	return 0;
}

