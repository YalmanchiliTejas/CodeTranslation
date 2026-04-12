#include<iostream>
#include<string>
using namespace std;
int ctoi(char c) {
	int i; char ch = '0';
	for (i = 0; i < 10; i++)if (ch == c)return i; else ch++;
	return -1;
}
int main() {
	string s;
	while (cin >> s) {
		if (s == "#")return 0;
		int map[10][110] = {};
		int h = 1, w = 1;
		//map[h][w]
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'b') {
				map[h][w] = 1;
				w++;
			}
			else if (s[i] == '/') {
				h++;
				w = 1;
			}
			else for (int j = 0; j < ctoi(s[i]); j++) {
				map[h][w] = 0;
				w++;
			}
		}
		w--;
		int tsu, ku, ko, ma;
		cin >> tsu >> ku >> ko >> ma;
		map[tsu][ku] = 0;
		map[ko][ma] = 1;
		for (int i = 1; i <= h; i++) {
			int cnt = 0;
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 1) {
					if (cnt)cout << cnt;
					cnt = 0;
					cout << 'b';
				}
				else 
					cnt++;
			}
			if (cnt)cout << cnt;
			if (i != h)cout << '/'; else cout << endl;
		}
	}
}