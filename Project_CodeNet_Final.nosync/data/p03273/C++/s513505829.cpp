#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int h, w; cin >> h >> w;
	char m[110][110];
	bool hp[110], wp[110];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)cin >> m[i][j];
	}

	for (int i = 0; i < h; i++) {
		hp[i] = false;
		for (int j = 0; j < w; j++)if (m[i][j] == '#')hp[i] = true;
	}
	for (int i = 0; i < w; i++) {
		wp[i] = false;
		for (int j = 0; j < h; j++)if (m[j][i] == '#')wp[i] = true;
	}

	for (int i = 0; i < h; i++) {
		if (hp[i]) {
			for (int j = 0; j < w; j++) {
				if (wp[j])cout << m[i][j];
			}
			cout << endl;
		}
	}
}