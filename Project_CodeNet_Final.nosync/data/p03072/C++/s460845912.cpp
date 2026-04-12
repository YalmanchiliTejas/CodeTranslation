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
int n, ans = 0, h[22];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
		bool ok = true;
		for (int j = 0; j < i; ++j)
			if (h[j] > h[i]) {
				ok = false;
				break;
			}

		if (ok)
			++ans;
	}

	cout << ans << endl;

	return 0;
}