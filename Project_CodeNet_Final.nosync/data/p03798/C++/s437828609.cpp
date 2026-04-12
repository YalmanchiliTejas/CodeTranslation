#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<bool> s;

bool check(vector<bool> &ans) {
	for (int i = 1; i < n-2; i++) {
		if ((s[i] && !ans[i]) || (!s[i] && ans[i])) {
			ans[i+1] = ans[i-1];
		} else {
			ans[i+1] = !ans[i-1];
		}
	}
	bool ret = true;
	if ((s[n-1] && !ans[n-1]) || (!s[n-1] && ans[n-1])) {
		ret &= ans[n-2] == ans[0];
	} else {
		ret &= ans[n-2] != ans[0];
	}
	if ((s[n-2] && !ans[n-2]) || (!s[n-2] && ans[n-2])) {
		ret &= ans[n-3] == ans[n-1];
	} else {
		ret &= ans[n-3] != ans[n-1];
	}
	return ret;
}

void printvec(vector<bool> &ans) {
	for (int i = 0; i < n; i++) {
		cout << "SW"[ans[i]];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string ch; cin >> n >> ch;
	for (int i = 0; i < n; i++) {
		if (ch[i] == 'o') s.push_back(true);
		else s.push_back(false);
	}
	for (int i = 0; i < 2; i++) {
		vector<bool> ans(n, false);
		ans[0] = bool(i);
		for (int j = 0; j < 2; j++) {
			if ((s[0] && !ans[0]) ||(!s[0] && ans[0])) {
				ans[1] = ans[n-1] = bool(j);
			} else {
				ans[1] = bool(j);
				ans[n-1] = !ans[1];
			}
			if (check(ans)) {
				printvec(ans);
				return 0;
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}