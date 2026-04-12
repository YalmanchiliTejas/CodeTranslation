#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll x, y;
	cin >> x >> y;
	ll counta = 0;
	ll countb = 0;
	ll countc = 0;
	bool fang = 0;
	if (c * 2 <= a + b) {
		countc += min(x, y)*2;
		if (x != y) {
			if (max(x, y) == x) {
				fang = true;
			}
			else {
				fang = false;
			}
			if (fang) {
				if (a <= c*2) {
					counta += x - y;
				}
				else {
					countc += (x - y)*2;
				}
			}
			else {
				if (b <= c*2) {
					countb += y - x;
				}
				else {
					countc += (y - x)*2;
				}
			}
		}
	}
	else {
		counta += x;
		countb += y;
	}
	cout << counta * a + countb * b + countc * c << endl;
}