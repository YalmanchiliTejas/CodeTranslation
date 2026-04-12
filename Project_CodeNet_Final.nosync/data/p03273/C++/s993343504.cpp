#include "bits/stdc++.h"
using namespace std;

int main() {
	
	int h, w;
	cin >> h >> w;
	set<int> hor, ver;
	string grid[h];
	for (int i=0; i<h; i++) {
		string s;
		cin >> s;
		for (int j=0; j<w; j++) {
			if (s[j] == '#') {
				hor.insert(i);
				ver.insert(j);
			}
		}
		grid[i] = s;
	}
	
	vector<int> f(hor.begin(), hor.end());
	vector<int> g(ver.begin(), ver.end());
	
	for (int i=0; i<f.size(); i++) {
		for (int j=0; j<g.size(); j++) {
			cout << grid[f[i]][g[j]];
		}
		cout << endl;
	}
	
}
