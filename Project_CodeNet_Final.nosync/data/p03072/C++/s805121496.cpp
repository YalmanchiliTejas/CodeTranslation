#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <cassert>
#include <string>
#include <climits>
#include <numeric>

#define all(x) begin(x),end(x)

using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	vector<int> h(n);
	int ans = 1;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	bool flag = true;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (h[i] < h[j])
				flag = false;
		}
		if (flag)
			ans++;
		flag = true;
	}
	cout << ans << endl;
}

