#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define INF 2140000000
#define MOD 1000000007

int main() {
	int n;

	cin >> n;
	
	vector<int> h(n);

	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	int ans = 1;

	for (int i = 1; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < i; ++j) {
			if (h[j] <= h[i]) {
				cnt++;
			}
		}

		if (cnt == i) {
			ans++;
		}
	}

	cout << ans << endl;
	



	return 0;
}