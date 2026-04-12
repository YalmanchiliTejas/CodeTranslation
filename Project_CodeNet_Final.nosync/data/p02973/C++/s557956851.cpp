#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, ans;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) cin >> a[i];

	multiset<int> s;
	multiset<int>::iterator it;

	for (i = n - 1; i >= 0; i--) {
		it = s.upper_bound(a[i]);
		if (it == s.end()) s.insert(a[i]);
		else {
			s.erase(it);
			s.insert(a[i]);
		}
	}

	ans = s.size();
	cout << ans << "\n";

	return 0;
}

