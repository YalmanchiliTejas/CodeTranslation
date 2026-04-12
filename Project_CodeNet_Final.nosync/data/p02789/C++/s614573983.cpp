#define _USE_MATH_DEFINES // M_PI
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define rREP(i,a,n) for(int (i)=(n)-1; (i)>=(a);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 2147483647;
constexpr ll mod = 1000000007;

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

	int a, b; cin >> a >> b;
	cout << (a == b ? "Yes" : "No") << "\n";




	return 0;
}
