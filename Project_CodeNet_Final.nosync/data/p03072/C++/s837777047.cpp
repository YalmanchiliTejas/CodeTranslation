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
	
	int n, i, j, k, x, ct;
	cin >> n;
	vector<int> h(n);
	for (i = 0; i < n; i++) cin >> h[i];
	x = h[0];
	ct = 1;
	for (i = 1; (i < n); i++) {
		if (h[i] >= x) ct++;
		x = max(x, h[i]);
	}
	cout << ct << "\n";

	return 0;
}
