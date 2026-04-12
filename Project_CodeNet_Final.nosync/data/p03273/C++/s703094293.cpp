#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s;
	int H = 0;
	for (int i = 0; i < h; i ++) {
		string t;
		cin >> t;
		bool ng = true;
		for (int j = 0; j < (int) t.size(); j ++) {
			if (t[j] == '#') ng = false;
		}
		if (!ng) {
			s.push_back(t);
			H ++;
		}
	}
	vector<bool> ngs(w);
	for (int i = 0; i < w; i ++) {
		bool ng = true;
		for (int j = 0; j < H; j ++) {
			if (s[j][i] == '#') {
				ng = false;
			}
		}
		ngs[i] = ng;
	}
	for (int i = 0; i < H; i ++) {
		for (int j = 0; j < w; j ++) {
			if (!ngs[j]) {
				cout << s[i][j];
			}
		}
		cout << endl;
	}
        return 0;
}
