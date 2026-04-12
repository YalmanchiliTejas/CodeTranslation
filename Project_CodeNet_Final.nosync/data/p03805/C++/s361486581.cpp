#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
typedef long long ll;

int n;
int m;

int main() {
	bool w[9][9] = {false};
	ll ans = 0;
	cin >> n >> m;
	vector<int> a(30), b(30);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		w[a[i]][b[i]] = true;
		w[b[i]][a[i]] = true;
	}
	vector<int> per(n);
	rep(i, n) per[i] = i + 1;
	do {
		if (per[0] != 1) break;
		bool exist = true;
		for (int i = 1; i < n && exist; i++) {
			if (!(w[per[i - 1]][per[i]])) exist = false;
		}
		if (exist) ans++;
	} while (next_permutation(per.begin(), per.end()));
	cout << ans << endl;
	return 0;
}
