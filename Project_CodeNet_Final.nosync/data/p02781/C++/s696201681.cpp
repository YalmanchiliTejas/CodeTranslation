// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 4e5 + 2;

string str;
int n, k;
vector<int> vv;

map<vector<int>, int> dp[1000][2];

int go(int id, bool f, vector<int> &vv) {
	{
		int ans = 0;
		for (auto it: vv) ans += it;
		if (ans > k) return 0;
	}
	if (id == n) {
		int ans = 0;
		for (auto it: vv) ans += it;
		// cout << ans << '\n';
		return ans == k;
	}
	if (dp[id][f].count(vv)) return dp[id][f][vv];
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		if (f == false && str[id]-'0' < i) break;
		if (i) vv[i]++;			
		ans += go(id+1, f|(i<(str[id]-'0')), vv);
		if (i) vv[i]--;
	}
	return dp[id][f][vv] = ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str >> k;
	n = str.size();
	vector<int> ok(10);
  cout << go(0,0,ok);
  return 0;
}
// 1). Try forming/rearranging the equations if any
// 2). If problem asks to count, try counting in reverse(it can be easier sometimes)