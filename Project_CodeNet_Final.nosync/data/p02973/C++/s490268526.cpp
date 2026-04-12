#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n;
	cin >> n;
	int a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (v.size() == 0 || v[v.size() - 1] >= a[i]) {
			v.push_back(a[i]);
		} else {
			int l = -1, r = v.size() - 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (v[m] < a[i])
					r = m;
				else
					l = m;
			}
			v[r] = a[i];
		}
	}
	cout << v.size() << endl;
}