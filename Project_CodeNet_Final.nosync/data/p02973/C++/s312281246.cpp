#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int nm = 1e5;
int n, a[nm], l[nm + 2] = { (int) 1e9 + 1 };

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	fill(l + 1, l + n + 1, -1);
	for (int i = 0; i < n; ++i) {
		int inf = 0, sup = n;
		while (sup - inf > 1) {
			int mid = (inf + sup) / 2;
			if (l[mid] >= a[i])
				inf = mid;
			else
				sup = mid;
		}
		l[inf + 1] = a[i];
	}

	for (int i = n; i >= 0; --i)
		if (l[i] >= 0) {
			cout << i << endl;
			return 0;
		}
}
