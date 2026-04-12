#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define rep(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rREP(i,m,n) for(int (i)=(n)-1; (i)>=(m);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 1000000001;
constexpr ll mod = 1000000007;
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

	int N; cin >> N;
	vector<map<char,int>>s(N);
	rep(i, 0, N) {
		string a; cin >> a;
		rep(j, 0, a.size()) {
			s[i][a[j]]++;
		}
	}
	string ans = "";
	for (auto p : s[0]) {
		int cnt = p.second;
		char ch = p.first;
		bool ok = true;
		rep(i, 1, N) {
			if (s[i].count(ch))chmin(cnt, s[i][ch]);
			else ok = false;
		}
		if (ok) {
			rep(i, 0, cnt) {
				ans += ch;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}