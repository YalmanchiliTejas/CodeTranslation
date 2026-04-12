#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> a(n);
	deque<ll> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2 == 0) {
			q.push_back(a[i]);
		}
		else {
			q.push_front(a[i]);
		}
	}
	if (n % 2 == 0) for (int i = 0; i < n; i++) {
		cout << q[i];
		if (i < n - 1) cout << " ";
		else cout << endl;
	}
	else for (int i = n - 1; i >= 0; i--) {
		cout << q[i] << endl;
		if (i < n - 1) cout << " ";
		else cout << endl;
	}
}
