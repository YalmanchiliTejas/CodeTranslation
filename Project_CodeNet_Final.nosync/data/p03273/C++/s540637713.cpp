#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int v[N], h[N];
string t[N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> t[i];
	
	// horizontal check
	for (int i = 0; i < n; i++) {
		bool temp = true;
		for (int j = 0; j < m; j++) {
			if (t[i][j] == '#') {
				temp = false;
				break;
			}
		}
		if (temp) {
			v[i] = 1;
		}
	}
	
	// vertical check
	for (int j = 0; j < m; j++) {
		bool temp = true;
		for (int i = 0; i < n; i++) {
			if (t[i][j] == '#') {
				temp = false;
				break;
			}
		}
		if (temp) {
			h[j] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		int temp = true;
		if (v[i] == 1) temp = false;
		else for (int j = 0; j < m; j++) if (h[j] != 1) cout << t[i][j];
		if (temp) cout << endl;
		
	}
	
	return 0;
}