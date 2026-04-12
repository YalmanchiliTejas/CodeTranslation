#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w; cin >> h >> w;
	vector<string> a(h); for (auto& e : a) cin >> e;
	vector<int> r(h, 0), c(w, 0);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') r[i]++, c[j]++;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (r[i] != w and c[j] != h) cout << a[i][j];
		}
		if (r[i] != w) cout << endl;
	}
}
