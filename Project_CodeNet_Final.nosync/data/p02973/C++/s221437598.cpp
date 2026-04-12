#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	reverse(a.begin(), a.end());
	vector<int> l(a.size() + 1, 0);
	l[0] = a[0];
	int len = 1;
	for (int i = 1; i < n; ++i) {
		if (l[len - 1] <= a[i]) l[len++] = a[i];
		else *upper_bound(l.begin(), l.begin() + len, a[i]) = a[i];
	}
	cout << len << endl;
	return 0;
}
