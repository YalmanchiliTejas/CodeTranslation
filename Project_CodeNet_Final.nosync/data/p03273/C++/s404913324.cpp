#include <iostream>
#include <vector>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> g(h);
	vector<int> hUse(h);
	vector<int> wUse(w);
	
	for (auto &&e : g) {
		cin >> e;
	}
	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (g[i][j] == '#') {
				hUse[i] = 1;
				wUse[j] = 1;
			}
		}
	}
	
	for (int i = 0; i < h; ++i) {
		if (hUse[i] == 0)
			continue;
		
		for (int j = 0; j < w; ++j) {
			if (wUse[j] == 0)
				continue;
			
			if (g[i][j] == '#') {
				cout << "#";
			} else {
				cout << ".";
			}
		}
		
		cout << endl;
	}
}