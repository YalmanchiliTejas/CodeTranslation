#include "bits/stdc++.h"
using namespace std;
#include "atcoder/all"
using namespace atcoder;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>istream&operator >>(istream&is,vector<T>&vec){for(T&x:vec)is>>x;return is;}
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1ll;
}

int target;
bool f(int a) {
	return a < target;
}

#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)

signed main(){
	IOS();
	int N, Q;
	cin >> N >> Q;
	vector<int>a(N);
	cin >> a;
	segtree<int, op, e> seg(a);
	REP(i, Q) {
		int t;
		cin >> t;
		if(t == 2) {
			int l, r;
			cin >> l >> r;
			--l;
			out(seg.prod(l, r));
		} else {
			int x, v;
			cin >> x >> v;
			--x;
			if(t == 1) {
				seg.set(x, v);
			} else {
				target = v;
				out(seg.max_right<f>(x) + 1);
			}
		}
	}
}