#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int H, W;
int cnt = 0;
string table[100];
map <int, bool> width;
map <int, bool> height;
bool flag;

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> table[i];
		for (int j = 0; j < W; j++) {
			if (table[i][j] == '#') {
				flag = true;
			}
		}
		if (!flag) {
			height[i] = true;
		}
		flag = false;
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (table[j][i] == '#') flag = true;
			
		}
		if (!flag) {
			width[i] = true;
		}
		flag = false;
	}
	string s[100];
	for (int i = 0; i < H; i++) {
		if (!height[i]) {
			for (int j = 0; j < W; j++) {
				if (width[j]) continue;
				else {
					s[cnt] += table[i][j];
				}
			}
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << s[i] << endl;
	}
	return 0;
}