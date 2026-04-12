#include <bits/stdc++.h>

#define int long long
#define double long double

using namespace std;

#define REP(i, a, b) for (int(i) = (a); i < (b); (i)++)
#define rep(i, n) REP(i, 0, n)
#define PER(i, a, b) for (int(i) = (a - 1); i >= (b); (i)--)
#define per(i, n) PER(i, n, 0)
#define each(i, n) for (auto &i : n)
#define clr(a) memset((a), 0, sizeof(a))
#define mclr(a) memset((a), -1, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define dum(val) cerr << #val " = " << val;
#define dump(val) cerr << #val " = " << val << endl;
#define FILL(a, v) fill(a, a + sizeof(a) / sizeof(*a), v)

typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int dx[8] = {+1, +0, -1, +0, +1, +1, -1, -1};
const int dy[8] = {+0, -1, +0, +1, -1, +1, -1, +1};
const int mod = 1e9 + 7;
const int INF = 1e9;

signed main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	deque<int> q;

	rep(i, n) {
		if (i % 2 == 0) {
			q.push_back(a[i]);
		} else {
			q.push_front(a[i]);
		}
	}

	rep(i, n) {
		if (n % 2 == 0) {
			cout << q[i] << " ";
		} else {
			cout << q[n - i - 1] << " ";
		}
	}
	cout << endl;

	return 0;
}
