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
			for (int j = 0; j < v.size(); j++) {
				if (v[j] < a[i]) {
					v[j] = a[i];
					break;
				}
			}
		}
	}
	cout << v.size() << endl;
}