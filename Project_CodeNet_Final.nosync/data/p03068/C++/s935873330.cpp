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
	string s; cin >> s;
	int k; cin >> k;
	vector<char> ans(n);
	char sk = s[k-1];
	for (int i = 0; i < n; ++i) {
		if (sk != s[i])
			ans[i] = '*';
		else
			ans[i] = s[i];
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i];
	cout << endl;
}

