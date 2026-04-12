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

	int n, m, i, j, k, x, y;
	cin >> n >> m;
	vector<string> s(n);
	for (i = 0; i < n; i++) cin >> s[i];
	vector<vector<bool>> b(n, vector<bool>(m, false));
	b[0][0] = true; 
	x = 0; y = 0;
	while (1) {
		if ((x < n - 1) && (s[x + 1][y] == '#')) {
			b[x + 1][y] = true;
			x++;
			continue;
		}
		if ((y < m - 1) && (s[x][y + 1] == '#')) {
			b[x][y + 1] = true;
			y++;
			continue;
		}
		break;
	}


	bool valid = true;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if ((s[i][j] == '#') && (!b[i][j])) valid = false;
		}
	}
	if (valid) cout << "Possible\n";
	else cout << "Impossible\n";

	return 0;
}
