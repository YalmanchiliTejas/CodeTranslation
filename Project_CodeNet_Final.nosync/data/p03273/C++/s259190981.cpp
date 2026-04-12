#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int h, w;
	cin >> h >> w;
	bool x[110] = { 0 }, y[110] = { 0 };
	vector<string>s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			if (s[i][j] == '#') {
				x[i] = true;
				y[j] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (x[i]) {
			for (int j = 0; j < w; j++) {
				if (y[j])cout << s[i][j];
			}
			cout << endl;
		}
	}
}

