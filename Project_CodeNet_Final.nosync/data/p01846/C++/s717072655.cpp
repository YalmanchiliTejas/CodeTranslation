#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(true) {
		cin >> s;
		if(s == "#") {
			break;
		}
		
		int m[15][15] = {0};
		int r = 0, c = 0;
		int w, h;
		
		for(char ch : s) {
			if(ch == '/') {
				r++;
				w = c;
				c = 0;
			} else if('0' <= ch && ch <= '9') {
				for(int j = 0; j < ch - '0'; j++) {
					c++;
				}
			} else if(ch == 'b') {
				m[r][c] = 1;
				c++;
			}
		}
		
		h = r + 1;
		
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			m[a - 1][b - 1] = 0;
			m[c - 1][d - 1] = 1;
		}
		
		for(int r = 0; r < h; r++) {
			int cnt = 0;
			for(int c = 0; c < w; c++) {
				if(m[r][c]) {
					if(cnt > 0) {
						cout << cnt;
						cnt = 0;
					}
					cout << 'b';
				} else {
					cnt++;
				}
			}
			if(cnt > 0) {
				cout << cnt;
			}
			
			if(r != h - 1) {
				cout << '/';
			} else {
				cout << endl;
			}
		}
	}
	return 0;
}
