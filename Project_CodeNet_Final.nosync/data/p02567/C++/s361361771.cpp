#include <bits/stdc++.h>
#include<random>
using namespace std; typedef unsigned long long _ulong; typedef long long int lint; typedef pair<lint, lint> plint; typedef pair<double long, double long> pld;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define endk '\n'
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const lint MOD = 1e9 + 7, INF = 1e18;
lint dx[8] = { 0, -1, 1, 0, 1, -1, 1, -1 }, dy[8] = { 1, 0, 0, -1, -1, -1, 1, 1 };
typedef pair<double, lint> Pa;
typedef pair<plint, lint> tlint;
struct edge {
	lint cost;
	lint u, v;
};

#include<atcoder/all>
using namespace atcoder;

lint op(lint a, lint b) { return max(a, b); }
lint e() { return -1; }
lint target;
bool f(lint v) { return v < target; }
lint N, Q, A;
lint T, X, V;
int main() {
	cin >> N >> Q;
	vector<lint> arr(N);
	REP(i, N) cin >> arr[i];
	segtree < lint, op, e > tree(arr);
	REP(i, Q) {
		cin >> T;
		if (T == 1) {
			cin >> X >> V; X--;
			tree.set(X, V);
		}
		else if (T == 2) {
			cin >> X >> V; X--;
			cout << tree.prod(X, V) << endk;
		}
		else {
			cin >> X >> target; X--;
			cout << tree.max_right<f>(X) + 1 << endk;
		}
	}
}
