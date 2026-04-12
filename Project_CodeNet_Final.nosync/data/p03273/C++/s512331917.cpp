#include<bits/stdc++.h>
using namespace std;


int main(void) {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < h; i++) {
		int tmp = 0;
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.')
				tmp++;	
		}
		if (tmp == w) {
            /*
			for (int k = i; k < h - 1; k++) {
				a[k] = a[k + i];
			}
            */
			a.erase(a.begin() + i);
			i--;
			h--;
		}
	}
	for (int i = 0; i < w; i++) {
		int tmp = 0;
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '.') {
				tmp++;
			}
		}
		if (tmp == h) {
			for (int k = 0; k < h; k++) {
				for (int l = i; l < w - 1; l++) {
					a[k][l] = a[k][l + 1];
				}
              	a[k].pop_back();
            }
            w--;
            i--;
		}
	}
    //cout << endl;
	for (int i = 0; i < h; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
