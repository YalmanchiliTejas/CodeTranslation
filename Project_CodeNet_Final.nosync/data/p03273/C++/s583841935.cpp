#include <bits/stdc++.h> 
using namespace std;
const int maxn = 107; 
int main()
{
	string ss[maxn], ans[maxn];
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		cin >> ss[i];
		ans[i] = ss[i];
	}
	for (int i = 0; i < h; ++i) {
		bool fg = true;
		for (int j = 0; j < w; ++j) if (ss[i][j] != '.') {
			fg = false;
			break;
		}
		if(fg) {
			for (int j = 0; j < w; ++j) {
				ans[i][j] = ' ';
			}
		}
	}
	for (int j = 0; j < w; ++j) {
		bool fg = true;
		for (int i = 0; i < h; ++i) if(ss[i][j] != '.') {
			fg = false;
			break;
		}
		if(fg) {
			for (int i = 0; i < h; ++i) {
				ans[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < h; ++i) {
		bool fg = false;
		for (int j = 0; j < w; ++j) if(ans[i][j] != ' ') {
			cout << ans[i][j];
			fg = true;
		}
		if(fg) cout << endl;
	} 
	
	return 0;
}