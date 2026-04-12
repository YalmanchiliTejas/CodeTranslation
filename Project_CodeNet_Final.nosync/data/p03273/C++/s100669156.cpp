// abc107_b.cc
#include <bits/stdc++.h>
using namespace std;

vector<string> clearRows(vector<string> v) {
	vector<string> ans;

	for (int i = 0; i < v.size(); i++) {
		bool to_delete = true;
		auto it = find(v[i].begin(), v[i].end(), '#');
		if (it != v[i].end()) to_delete = false;
		if (!to_delete) ans.push_back(v[i]);
	}

	return ans;
} 

vector<string> leftMove(vector<string> v) {
	int len = v.empty() ? 0 : v[0].size();
	vector<string> ans(len);

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].length() - 1; j >= 0; j--) {
			ans[len - j - 1].push_back(v[i][j]);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (auto& e : s)
		cin >> e;

	s = clearRows(s);
	s = leftMove(s);
	s = clearRows(s);
	s = leftMove(s);
	s = leftMove(s);
	s = leftMove(s);

	for (auto e : s) {
		for (auto c : e) {
			cout << c;
		}
		cout << "\n";
	}

}