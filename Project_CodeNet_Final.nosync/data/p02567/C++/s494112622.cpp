#define _CRT_SECURE_NO_WARNINGS
#include <atcoder/all>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

#define BIT(nr) (1UL << (nr))
#define int long long
//#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

using namespace std;
using namespace atcoder;

int op(int a, int b) {
	return max(a, b);
}
int e() {
	return -LL_HALFMAX;
}

signed main() {
	int N, Q;
	cin >> N >> Q;
	
	vector<int> A(N + 1);
	REPS(i, N) {
		cin >> A[i];
	}


	segtree<int, op, e> seg(A);
	vector<int> T(Q), f(Q), s(Q);

	rep(i, Q) {
		cin >> T[i] >> f[i] >> s[i];
	}

	rep(i, Q) {
		if (T[i] == 1) {
			int X = f[i], V = s[i];
			seg.set(X, V);

		}
		else if(T[i] == 2){
			int L = f[i], R = s[i] + 1;
			int ans = seg.prod(L, R);
			cout << ans << "\n";
		}
		else {
			int X = f[i], V = s[i];
			int ans = seg.max_right(X, [&](int S) {
				if (S <= V - 1) {
					return true;
				}
				return false;
			});

			cout << ans << "\n";
		}
	}

	return 0;
}