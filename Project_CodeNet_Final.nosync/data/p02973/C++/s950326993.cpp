#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		auto it = m.lower_bound(a);
		if (m.size() == 0 || it == m.begin()) {
			m[a]++;
			res++;
		} else {
			it--;
			m[it->first]--;
			if (m[it->first] == 0) {
				m.erase(it->first);
			}
			m[a]++;
		}
	}
	cout << res << endl;
}
