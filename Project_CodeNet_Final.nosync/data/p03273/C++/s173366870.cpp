#include<iostream>
using namespace std;
int main() {
	int h, w;
	int a[110], b[110];
	char s[110][110];
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			if (s[i][j] == '#')
				a[i] = 1, b[j] = 1;
		}
	}
	for (int i = 1; i <= h; i++) {
		if (a[i] == 1) {
			for (int j = 1; j <= w; j++)
				if (b[j] == 1) cout << s[i][j];
			cout << endl;
		}
	}
	return 0;
}
