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

	long long n, i, j, k, ans, c1, c2;
	cin >> n;
	vector<long long> a(n), b(n, 0), c(n, 0);
	for (i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.end());
	c1 = 0; c2 = 0;
	for (i = 1; i < n; i++) {
		if (i % 2 == 1) b[i]++, b[i - 1]--;
		else b[i - 1]++, b[i]--;

		if (i % 2 == 1) c[i]--, c[i - 1]++;
		else c[i - 1]--, c[i]++;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	c1 = 0; c2 = 0;
	for (i = 0; i < n; i++) {
		c1 += a[i] * b[i];
		c2 += a[i] * c[i];
	}


	ans = max(c1, c2);
	cout << ans << "\n";
		
	return 0;
}
