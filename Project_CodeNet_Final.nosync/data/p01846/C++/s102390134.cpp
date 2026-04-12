#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int>x[10]; int a, b, c, d; string S, T;
int main() {
	while (true) {
		cin >> S; int p = 0; if (S == "#")break; cin >> a >> b >> c >> d; a--; b--; c--; d--; S += '/';
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '/') {
				for (int j = 0; j < T.size(); j++) { 
					if (T[j] == 'b')x[p].push_back(1);
					else { for (int k = 0; k < (T[j] - '0'); k++)x[p].push_back(0); }
				}
				p++; T = "";
			}
			else { T += S[i]; }
		}
		swap(x[a][b], x[c][d]);
		for (int i = 0; i < p; i++) {
			int c = 0;
			for (int j = 0; j < x[i].size(); j++) {
				if (x[i][j] == 0) { c++; }
				if (x[i][j] == 0 && (j == x[i].size() - 1 || x[i][j + 1] == 1)) { cout << c; c = 0; }
				if (x[i][j] == 1)cout << 'b';
			}
			if (i < p - 1)cout << '/';
		}
		cout << endl; for (int i = 0; i < 10; i++)x[i].clear();
	}
	return 0;
}