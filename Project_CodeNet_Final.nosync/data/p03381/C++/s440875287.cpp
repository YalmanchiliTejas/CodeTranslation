#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
pair<int,int> a[N];	
int res[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i) {
		if (i <= n / 2) {
			res[a[i].second] = a[n / 2 + 1].first;
		} else {
			res[a[i].second] = a[n / 2].first;
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d\n", res[i]);
	}
}