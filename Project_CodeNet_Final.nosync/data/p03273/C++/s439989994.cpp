#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	string a[h];
	vector<bool> ch(h, true);
	vector<bool> cw(w, true);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				ch[i] = false;
				cw[j] = false;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if ((ch[i] || cw[j]) == false)
				cout << a[i][j];
		}
        if (ch[i] == false)
		    cout << endl;
	}
	return 0;
}