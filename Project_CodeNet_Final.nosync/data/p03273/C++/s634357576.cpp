#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define ull unsigned long long
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;
const int MOD=1e9+7;
int main(void) {
int h;
	cin >> h;
	int w;
	cin >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}

	vector<bool> row(h, false);
	vector<bool> col(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0; j < w; j++) {
				if (col[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}
