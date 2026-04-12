#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n;
	string s,sum="";
	cin >> n;
	map<char, int>mp,tmp;
	cin >> s;
	for (auto c : s)mp[c]++;
	rep(i, n-1) {
		tmp.clear();
		cin >> s;
		for (auto c : s)tmp[c]++;
		rep(j, 26)mp['a' + j] = min(mp['a' + j], tmp['a' + j]);
	}
	for (auto p : mp) {
		if (p.second != 0) {
			rep(i, p.second)sum += p.first;
		}
	}
	sort(all(sum));
	cout << sum << endl;
	return 0;
}

