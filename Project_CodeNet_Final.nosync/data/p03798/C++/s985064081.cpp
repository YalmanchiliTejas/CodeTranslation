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

	int n, i, j, k;
	string s;
	cin >> n >> s;
	s = s + s;

	vector<int> ans, a(n);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			a[0] = i;
			a[1] = j;

			for (k = 2; k < n; k++) {
				if (a[k - 1] == 0) {
					if (s[k - 1] == 'o') a[k] = a[k - 2];
					else a[k] = 1 - a[k - 2];
				}
				else {
					if (s[k - 1] == 'o') a[k] = 1 - a[k - 2];
					else a[k] = a[k - 2];
				}
			}

			bool v1 = false, v2 = false;
			if (a[0] == 0) {
				if ((s[0] == 'o') && (a[n - 1] == a[1])) v1 = true;
				if ((s[0] == 'x') && (a[n - 1] != a[1])) v1 = true;
			}
			else {
				if ((s[0] == 'o') && (a[n - 1] != a[1])) v1 = true;
				if ((s[0] == 'x') && (a[n - 1] == a[1])) v1 = true;
			}

			if (a[n - 1] == 0) {
				if ((s[n - 1] == 'o') && (a[n - 2] == a[0])) v2 = true;
				if ((s[n - 1] == 'x') && (a[n - 2] != a[0])) v2 = true;
			}
			else {
				if ((s[n - 1] == 'o') && (a[n - 2] != a[0])) v2 = true;
				if ((s[n - 1] == 'x') && (a[n - 2] == a[0])) v2 = true;
			}

			if (v1 && v2) {
				ans = a;
			}
		}
	}

	if (ans.empty()) cout << "-1\n";
	else {
		for (i = 0; i < n; i++) {
			if (ans[i] == 0) cout << "S";
			else cout << "W";
		}
		cout << "\n";
	}

	return 0;
}

