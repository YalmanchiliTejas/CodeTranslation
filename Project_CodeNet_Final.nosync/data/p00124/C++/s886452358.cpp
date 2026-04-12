#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a = 0;

	while (1) {
		int n, w, l, d;
		vector<string> name(10);

		cin >> n;
		if (n == 0) break;
		if (a == 1) cout << endl;
		vector< pair<int, int> > vp(n);

		for (int i = 0; i < n; i++) {
			cin >> name[i];
			cin >> w >> l >> d;
			
			int p = 3 * w + d;

			vp[i].first = p;
			vp[i].second = (-1) * i;
		}
		sort(vp.begin(), vp.end());
		for (int i = n - 1; i >= 0; i--) {
			cout << name[vp[i].second * (-1)] << "," << vp[i].first << endl;
		}
		a = 1;
	}
}
