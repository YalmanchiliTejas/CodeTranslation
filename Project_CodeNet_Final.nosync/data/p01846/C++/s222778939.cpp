#include <iostream>
#include <string>
#include <vector>

using namespace std;

int w, h;
int main() {
	string s;
	int a, b, c, d;
	vector<string> ss;
	while (cin >> s && s != "#") {
		cin >> a >> b >> c >> d; a--; b--; c--; d--;
		ss.clear();
		int lastpos = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '/') {
				ss.push_back(s.substr(lastpos, i-lastpos));
				lastpos = i+1;
			}
		}
		ss.push_back(s.substr(lastpos, s.size()-lastpos));
		h = ss.size();
		auto bs = vector<vector<bool>>(h);
		for (int i = 0; i < h; i++) {
			auto t = vector<bool>();
			for (int j = 0; j < ss[i].size(); j++) {
				if (ss[i][j] == 'b') t.push_back(true);
				else for (int k = 0; k < ss[i][j]-'0'; k++) t.push_back(false);
			}
			bs[i] = t;
		}
		w = bs[0].size();
		bs[a][b] = false;
		bs[c][d] = true;
		string out = "";
		for (int i = 0; i < h; i++) {
			int count = 0;
			for (int j = 0; j < w; j++) {
				if (bs[i][j]) {
					if (count != 0) {
						out += (count + '0');
						count = 0;
					}
					out += 'b';
				}
				else count++;
			}
			if (count != 0) out += (count + '0');
			if (i != h - 1) out += '/';
		}
		cout << out << endl;
	}
}