#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	char A[100][100];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> A[i][j];
		}
	}
	int H[100], W[100];
	for (int i = 0; i < h; i++) {
		int  flag = 0;
		for (int j = 0; j < w; j++) {
			if (A[i][j] == '#')flag = 1;
		}
		if (flag == 1)H[i] = 1;
	}
	for (int j = 0; j < w; j++) {
		int flag = 0;
		for (int i = 0; i < h; i++) {
			if (A[i][j] == '#')flag = 1;
		}
		if (flag == 1)W[j] = 1;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (H[i]==1 && W[j]==1)cout << A[i][j];
		}
		cout << endl;
	}
}