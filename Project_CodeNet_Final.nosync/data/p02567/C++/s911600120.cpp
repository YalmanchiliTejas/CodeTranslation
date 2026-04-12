#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, Q;
//---------------------------------------------------------------------------------------------------
int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -1;
}
int tmp;
bool f(int x) {
	return x < tmp;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> Q;
	vector<int> v(N);
	rep(i, 0, N) cin >> v[i];
	segtree<int, op, e> st(v);
	rep(q, 0, Q) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) st.set(a - 1, b);
		else if (t == 2) {
			int ans = st.prod(a - 1, b);
			printf("%d\n", ans);
		}
		else {
			tmp = b;
			int ans = st.max_right<f>(a - 1) + 1;
			printf("%d\n", ans);
		}
	}
}





