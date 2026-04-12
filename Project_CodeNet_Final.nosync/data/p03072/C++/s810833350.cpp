#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>

using namespace std;
int n, ans, h[22], f[22];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];

	f[1] = 1;
	ans = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = 1;

		int j = i-1;
		while (j > 0 && h[i] >= h[j]) {
			f[i] += f[j];
			j -= f[j];
		}

		if (f[i] == i)
			++ans;
	}

	cout << ans << endl;

	return 0;
}