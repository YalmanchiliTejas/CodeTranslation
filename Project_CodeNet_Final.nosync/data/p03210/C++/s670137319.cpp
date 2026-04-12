#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(i, n) repi(i, 0, n)
#define rerepi(i, a, b) for(int i = int(a)-1; i >= b; --i)
#define rerep(i, n) rerepi(i, n, 0)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) {o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

// 降順ソート
// std::sort(data.begin(),data.end(),std::greater<int>());
// 昇順ソート
// std::sort(data.begin(),data.end());

const long long INF = 1LL << 60;

// ここから開始だよ！
ll X;

int main() {
	// 呪文エリア
	cin.tie(0);
	ios::sync_with_stdio(false);
	// 詠唱完了

	cin >> X;
	if (X == 7 || X == 5 || X == 3) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
