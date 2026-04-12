#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];
		
	deque<int> d;
	for (int i = 0; i < N;++i) {
		int p = lower_bound(d.begin(),d.end(),a[i])-d.begin();
		if (p == 0) d.push_front(a[i]);
		else d[p - 1] = a[i];
	}

	int ans = d.size();
	cout << ans << endl;
}
