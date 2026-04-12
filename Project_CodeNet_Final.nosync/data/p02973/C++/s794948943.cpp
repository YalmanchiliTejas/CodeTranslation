#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;

int n;
int a[N];
int fw[N];

void maximize(int &a, int b) { 
	if (a < b) a = b;
}

void upd(int i, int v) {
	for (; i >= 1; i -= i & -i) maximize(fw[i], v);
}

int get(int i) {
	int r = 0;
	for (; i <= n; i += i & -i) maximize(r, fw[i]);
	return r;
}

void compress() {
	vector <int> zip; zip.push_back(-1);
	for (int i = 1; i <= n; i++) zip.push_back(a[i]);
	sort(zip.begin(), zip.end());
	zip.resize(distance(zip.begin(), unique(zip.begin(), zip.end())));
	for (int i = 1; i <= n; i++) a[i] = lower_bound(zip.begin(), zip.end(), a[i]) - zip.begin();
}

int main() {
	//freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	compress();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = get(a[i]);
		maximize(ans, temp + 1);
		upd(a[i], temp + 1);
	}
	printf("%d\n", ans);
	return 0;
}