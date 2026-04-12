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
int main() {
	ll k, a, b;
	cin >> k >> a >> b;
	ll count = 0;
	if (a < k && a <= b) {
		cout << -1 << endl;
	}
	else {
		if (a >= k) {
			cout << 1 << endl;
		}
		else {
			count = k - a;
			if (count % (a - b) == 0) {
				cout << count / (a - b)*2 + 1 << endl;
			}
			else {
				cout << (count / (a - b)+1)*2 + 1 << endl;
			}
		}
	}
}