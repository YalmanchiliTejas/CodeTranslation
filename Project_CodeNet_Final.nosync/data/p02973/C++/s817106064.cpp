#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = int(1e5) + 7;

void init() {

}

void solve() {
	int n; scanf("%d", &n);
	vector<int> v(1);
	scanf("%d", &v[0]);
	v[0] = -v[0];
	for (int i = 0; i < n - 1; i++) {
		int p; scanf("%d", &p);
		vector<int>::iterator it = upper_bound(v.begin(), v.end(), -p);
		if (it == v.end()) v.push_back(-p);
		else *it = -p;
	}
	printf("%d\n", v.size());

}

const bool mtc = false;

int main() {
	int t;
	if (mtc) {
		scanf("%d", &t);
		while (t--) solve();
	}
	else solve();
}
