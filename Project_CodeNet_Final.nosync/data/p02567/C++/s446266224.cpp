#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#include <atcoder/all>
#define InfL 2000000000
#define InfLL 4000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -1;
}

int target;

bool f(int v) {
	return (v < target);
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vi A(N);
	rep(i, N)
		cin >> A[i];
	segtree<int, op, e> seg(A);
	rep(q, Q) {
		int T;
		cin >> T;
		int X, V, L, R;
		switch (T)
		{
		case 1:
			cin >> X >> V;
			X--;
			seg.set(X, V);
			break;
		case 2:
			cin >> L >> R;
			L--;
			cout << seg.prod(L, R) << endl;
			break;
		case 3:
			cin >> X >> V;
			target = V;
			X--;
			cout << seg.max_right<f>(X) + 1 << endl;
			break;
		}
	}
	return 0;
}