#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
#define pb push_back

#define N 210
int n, a[N];
vector<int> A;

void rot(int k) {
	if (k == 0) return;
	A.pb(k);
	for (int i = k; i < n; i ++) swap(a[i], a[i-k]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	while (true) {
		bool F = false;
		for (int i = 0; i < n; i ++) {
			if (a[0] != 0 && a[n-1] > a[0]) {
				F = true;
				rot(n-1);
			}
			rot(1);
		}
		if (!F) break;
	}
	while (a[0] != 0) rot(1);
	printf ("%d\n", (int) A.size());
	for (int i = 0; i < (int) A.size(); i ++)
		cout << A[i] << endl;
	for (int i = 0; i < n; i ++) assert(a[i] == i);
	return 0;
}
