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
const double pi = 3.141592653589793238;

int main() {
	int k[15];
	for (int i = 0; i < 12; ++i) { cin >> k[i]; }
	sort(k, k + 12);
	if (k[0] == k[3] && k[4] == k[7] && k[8] == k[11]) { cout << "yes" << endl; }
	else { cout << "no" << endl; }
}

