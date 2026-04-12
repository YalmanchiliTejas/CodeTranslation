#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

#include <atcoder/segtree>

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -INF;
}

int V;

bool f(int x) {
	return x < V;
}

int main() {
	int N, Q;
	cin >> N >> Q;
	atcoder::segtree<int, op, e> seg(N);
	REP(i, N) {
		int a;
		scanf("%d", &a);
		seg.set(i, a);
	}
	
	while (Q--) {
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t == 1) seg.set(a - 1, b);
		else if (t == 2) printf("%d\n", seg.prod(a - 1, b));
		else {
			V = b;
			printf("%d\n", seg.max_right<f>(a - 1) + 1);
		}
	}
	return 0;
}
