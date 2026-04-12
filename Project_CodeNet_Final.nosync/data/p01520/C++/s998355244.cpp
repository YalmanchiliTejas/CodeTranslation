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
	int a, b, c, k[105];
	cin >> a >> b >> c;
	for (int i = 0; i < a; ++i) { cin >> k[i]; }
	int ans = -1;
	for (int i = b - c; i <= b + c; ++i) {
		for (int j = 0; j < a; ++j) {
			if (i%k[j] == 0) {
				cout << j + 1 << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
