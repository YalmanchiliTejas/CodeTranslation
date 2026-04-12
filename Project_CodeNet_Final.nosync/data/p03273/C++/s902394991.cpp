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

	int n, m, i, j, k;
	cin >> n >> m;
	vector<string> s(n);
	vector<bool> ux(n, false), uy(m, false);
	for (i = 0; i < n; i++) {
		cin >> s[i];
		for (j = 0; j < m; j++) {
			if (s[i][j] == '#') ux[i] = true, uy[j] = true;
		}
	}

	for (i = 0; i < n; i++) {
		if (!ux[i]) continue;
		for (j = 0; j < m; j++) {
			if (uy[j]) cout << s[i][j];
		}
		cout << "\n";
	}

	return 0;
}
