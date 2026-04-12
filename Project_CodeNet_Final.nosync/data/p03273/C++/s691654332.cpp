#include<iostream>
using namespace std;
int main() {
	int h, w;
	cin >> h;
	cin >> w;
	char ch;
	int a[100][100];
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> ch;
			if (ch == '.') {
				a[i][j] = 0;
			}
			else {
				a[i][j] = 1;
			}
		}
	}
	int check = 0;

	for (int i = 0;i < w;i++) {
		for (int j = 0;j < h;j++) {
			if (a[j][i] == 1) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			for (int j = 0;j < h;j++) {
				a[j][i] = 2;
			}
		}
		check = 0;
	}

	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			if (a[i][j] == 1) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			for (int j = 0;j < w;j++) {
				a[i][j] = 3;
			}
		}
		check = 0;
	}
	
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			if (a[i][j] == 0) {
				cout << ".";
			}
			if (a[i][j] == 1) {
				cout << "#";
			}
		}
		if (a[i][w - 1] != 3) {
			cout << endl;
		}
	}
	return 0;
}