#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> s(H);

	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}
	vector<bool> a(H, false);
	vector<bool> b(W, false);

	for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
			if (s[i][j] == '#') {
				a[i] = true;
				b[j] = true;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		if (a[i]) {
			for (int j = 0; j < W; j++) {
				if (b[j]) {
					cout << s[i][j];
				}
			}
			cout<<endl;
		}
		
	}

	return 0;
}