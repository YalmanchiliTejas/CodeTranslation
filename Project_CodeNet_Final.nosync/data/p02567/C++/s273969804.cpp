#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using vvi = vector<vi>; using vl = vector<ll>; using vvl = vector<vl>;
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (int CNT = (int)(START); CNT < (int)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (int CNT = (int)(START); CNT > (int)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#include <atcoder/all>
using namespace atcoder;

int N;

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -1;
}

void show(segtree<int, op, e> s) {
	cout << "[";
	rep(i, N) cout << s.get(i) << ", ";
	cout << "]\n";
}

int main() {
	// 1-indを0-indに直す
	int Q; cin >> N >> Q;
	vi A(N); rep(i, N) cin >> A[i];
	segtree<int, op, e> s(A);
	while (Q--) {
		int T; cin >> T;
		if (T == 1) {
			int X, V; cin >> X >> V;
			s.set(X - 1, V);

		} else if (T == 2) {
			int L, R; cin >> L >> R;
			cout << s.prod(L - 1, R) << endl;

		} else if (T == 3) {
			int X, V; cin >> X >> V;
			function<bool(int)> f = [&](int x) {
				return x < V;
			};
			cout << s.max_right<function<bool(int)>>(X - 1, f) + 1 << endl;
		}
		
		// show(s);
	}
}
