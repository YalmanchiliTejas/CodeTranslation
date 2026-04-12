#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;
int board[10][10];
string s;

void input() {
	H = W = 0;
	int i = 0, j = 0;
	for(auto c : s) {
		if(c == 'b') {
			board[i][j] = 1;
			j++;
		}
		else if(c == '/') {
			i++;
			W = j;
			j = 0;
		}
		else {
			for(int k = 0; k < c - '0'; k++) {
				board[i][j] = 0;
				j++;
			}
		}
	}
	H = i + 1;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;
	board[a][b] = 0;
	board[c][d] = 1;
}

void output() {
	for(int i = 0; i < H; i++) {
		int s = 0;
		for(int j = 0; j < W; j++) {
			if(board[i][j]) {
				if(s != 0) {
					cout << s;
					s = 0;
				}
				cout << 'b';
			}
			else {
				s++;
			}
		}
		if(s != 0) cout << s;
		if(i != H - 1) cout << '/';
	}
	cout << endl;
}

void solve() {
	input();
	output();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(cin >> s, s != "#") solve();
}