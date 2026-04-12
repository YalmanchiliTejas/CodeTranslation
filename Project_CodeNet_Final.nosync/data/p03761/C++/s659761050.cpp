#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-7
#define inf 0x3f3f3f3f
#define mod 1000000007ll
using namespace std;

int main() {
	speed;
	int n;
	cin >> n;
	string s;
	vector<vector<int>>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		vector<int>t(255);
		for (int i = 0; i < s.size(); ++i)
			t[s[i]]++;
		v[i] = t;
	}
	vector<int>ans(255, inf);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 255; ++j)
			ans[j] = min(ans[j], v[i][j]);
	for (int i = 0; i < 255; ++i)
		cout << string(ans[i], i);
}