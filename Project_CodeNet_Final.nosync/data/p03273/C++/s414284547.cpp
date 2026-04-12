#include<iostream>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	char a[100][100];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	int b[100];
	int p = 0;
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				b[p] = i;
				p++;
				count++;
				break;
			}
		}
	}

	int c[100];
	int q = 0;
	int counta = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '#') {
				c[q] = i;
				q++;
				counta++;
				break;
			}
		}
	}

	for (p = 0; p < count;p++) {
		for (q = 0; q < counta;q++) {
			cout << a[b[p]][c[q]];
		}
		cout << endl;
	}

	return 0;
}