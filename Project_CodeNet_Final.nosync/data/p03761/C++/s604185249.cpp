#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define rep(i,m,n) for(int (i)=(m);(i)<(n);++(i))
#define rREP(i,m,n) for(int (i)=(n)-1;(i)>=(m);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr double PI = 3.1415926535897932;
template<class T>inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void init() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

int main() {
	init();

	int n; cin >> n;
	vector<string>vec(n);
	rep(i, 0, n)cin >> vec[i];

	string ans;
	vector<map<char, int>>mp(n);
	rep(i, 0, n) {
		rep(j, 0, vec[i].size())mp[i][vec[i][j]]++;
	}
	for (auto p : mp[0]) {
		bool ok = true;
		int cnt = p.second;
		rep(i, 1, n) {
			if (!mp[i].count(p.first)) {
				ok = false;
				break;
			}
			chmin(cnt, mp[i][p.first]);
		}
		if (ok) {
			string a = string(cnt, p.first);
			ans += a;
		}
	}
	sort(all(ans));
	cout << ans << "\n";

	return 0;
}