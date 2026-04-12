#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	int h, w;
	cin >> h >> w;
	vector<vector<char>> g(h, vector<char>(w));
	vector<int> r(h), c(w);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < h; i++) {
		bool f = true;
		for(int j = 0; j < w; j++) {
			if(g[i][j] == '#') f = false;
		}
		if(f) r[i]++;
	}
	for(int i = 0; i < w; i++) {
		bool f = true;
		for(int j = 0; j < h; j++) {
			if(g[j][i] == '#') f = false;
		}
		if(f) c[i]++;
	}
	for(int i = 0; i < h; i++) {
		if(r[i]) continue;
		for(int j = 0; j < w; j++) {
			if(c[j]) continue;
			cout << g[i][j];
		}
		cout << endl;
	}
	return 0;
}

