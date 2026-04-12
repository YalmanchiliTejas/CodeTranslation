#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
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

	string s;cin >> s;
	int cnt = 0;
	char a = s[0];
	rep(i, s.size()) {
		if (a == s[i])++cnt;
	}
	cout << (cnt == 3 ? "No" : "Yes") << "\n";
		
	return 0;
}