#include<iostream>
#include<cmath>
using namespace std;
int n, q, a[100009], b[100009], c[100009], d[100009], e[100009];
int main() {
	cin >> n >> q; c[0] = 1;
	for (int i = 1; i <= q; i++) { cin >> a[i] >> b[i]; if (c[i - 1] == a[i])c[i] = b[i]; else if (c[i - 1] == b[i])c[i] = a[i]; else c[i] = c[i - 1]; }
	for (int i = 1; i <= n; i++) { d[i] = i; if (abs(d[i] - c[q]) <= 1)e[i] = 1; }
	for (int i = q; i >= 1; i--) {
		swap(d[a[i]], d[b[i]]);
		e[d[c[i - 1] - 1]] = 1; e[d[c[i - 1]]] = 1; e[d[c[i - 1] + 1]] = 1;
	}
	int cnt = 0; for (int i = 1; i <= n; i++)cnt += e[i];
	cout << cnt << endl;
	return 0;
}