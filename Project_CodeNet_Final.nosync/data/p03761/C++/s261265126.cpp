#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int mod = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_map<char, int> cur, prev, ans;
	string s;
	cin >> s;
	for (int j = 0; j < (int) s.size(); j++) {
		prev[s[j]]++;
	}
	for (int i = 1; i < n; i++) {
		cin >> s;
		for (int j = 0; j < (int) s.size(); j++) {
			cur[s[j]]++;
		}
		for (int j = 0; j < (int) s.size(); j++) {
			if (prev[s[j]] != 0){
				ans[s[j]] = min (prev[s[j]] , cur[s[j]]);
			}
		}
		prev = ans;
		cur.clear();
		ans.clear();
	}
	string sans;
	for (auto i : prev) {
		if (i.second != 0) {
			for (int j = 0 ; j < i.second ; j++) sans += i.first;
		}
	}
	sort(sans .begin() , sans.end());
	cout << sans << endl;
}

