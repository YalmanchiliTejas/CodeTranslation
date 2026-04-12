#include<iostream>
#include<string>
#include<vector>
using namespace std;

string k = "..................";
int main() {
	string a;
	while (cin >> a, a!="#") {
		a += "/";
		string b;
		vector<string>c;
		for (char d : a) {
			if (d == '/') {
				c.push_back(b);
				b = "";
			}
			else b += d;
		}
		vector<string>e;
		for (string d : c) {
			string g;
			for (char f : d) {
				if (f == 'b')g += f;
				else g += k.substr(0, f - '0');
			}
			e.push_back(g);
		}
		int n, m, x, y; cin >> n >> m >> x >> y; n--; m--; x--; y--;
		e[n][m] = '.'; e[x][y] = 'b';
		for (int i = 0; i < e.size(); i++) {
			if (i)cout << "/";
			for (int j = 0; j < e[i].length(); j++) {
				if (e[i][j] == 'b')cout << 'b';
				else {
					int l = j;
					for (; l < e[i].length() - 1; l++) {
						if (e[i][l+1] == 'b')break;
					}
					cout << l - j + 1;
					j = l;
				}
			}
		}
		cout << endl;
	}
}