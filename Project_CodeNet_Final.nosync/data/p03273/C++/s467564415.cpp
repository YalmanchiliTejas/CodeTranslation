#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main() {
	char s[1000][1000];
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	int cnt = 0;
	//縦
	for (int i = 0; i < h; i++) {
		cnt = 0;
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') cnt++;
			if (cnt == w) {
				for (int l = i; l < h - 1; l++) {
					for (int k = 0; k < w; k++) {
						s[l][k] = s[l + 1][k];
					}
				}
				i--;
				h--;
			}
 		}
	}
	for (int i = 0; i < w; i++) {
		cnt = 0;
		for (int j = 0; j < h; j++) {
			if (s[j][i] == '.') cnt++;
			if (cnt == h) {
				for (int l = i; l < w - 1; l++) {
					for (int k = 0; k < h; k++) {
						s[k][l] = s[k][l + 1];
					}
				}
				i--;
				w--;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << s[i][j];
		}
		cout << endl;
	}


}