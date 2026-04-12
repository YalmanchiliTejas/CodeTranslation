#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > d(n, vector<int>(n, 0));
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		d[a-1][b-1] = d[b-1][a-1] = 1;
	}
	vector<int> c;
	for (int i = 1; i < n; i++) {
		c.push_back(i);
	}
	long long int cc = 0;
	do {
		bool h = true;
		if (d[0][c[0]] == 1) {
			for (int i = 0; i < n-2; i++) {
				if (d[c[i]][c[i+1]] == 1) {
				} else {
					h = false;
				}
			}
		} else {
			h = false;
		}
		if (h) {
			cc++;
		}
	} while(next_permutation(c.begin(), c.end()));
	cout << cc << endl;
	return 0;
}