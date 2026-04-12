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
	string s, ss = "";
	vector<int> c(26), maxx(26, 10000);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		c.assign(26, 0);
		for (auto ch : s) c[ch - 'a']++;
		for (j = 0; j < 26; j++) maxx[j] = min(maxx[j], c[j]);
	}
	ss = "";
	for (i = 0; i < 26; i++) {
		if (maxx[i] > 0) {
			s = "a";
			s[0] = 'a' + i;
			for (j = 0; j < maxx[i]; j++) {
				ss = ss + s;
			}
		}
	}
	cout << ss << "\n";

	return 0;
}
