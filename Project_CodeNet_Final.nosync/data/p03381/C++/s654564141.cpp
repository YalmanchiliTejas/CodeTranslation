#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 2e5 + 10;
int n, a[MAXN], b[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	sort(a, a + n);
	int f = a[n / 2 - 1], s = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (b[i] <= f)
			cout << s;
		else
			cout << f;
		cout << '\n';
	}
}