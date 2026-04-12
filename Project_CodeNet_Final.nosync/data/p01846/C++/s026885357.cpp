#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	string str;
	while (cin >> str) {
		if (str == "#") break;
		vector<vector<char>> masu(1);
		int r = 0;
		for (int i = 0; i < str.length();i++) {
			if (str[i] == 'b') masu[r].push_back(str[i]);
			else if (str[i] == '/') { r++; masu.push_back(vector<char>(0)); }
			else {
				int key = str[i] - '0';
				for (int j = 0; j < key;j++) masu[r].push_back('.');
			}
		}
		int a, b, c, d; cin >> a >> b >> c >> d;
		swap(masu[a-1][b-1], masu[c-1][d-1]);
		for (int i = 0; i < masu.size();i++) {
			for (int j = 0; j < masu[0].size();j++) {
				if (masu[i][j] == 'b') cout << 'b';
				else {
					int k = j;
					for (;k < masu[0].size();k++) {
						if (masu[i][k] == 'b') { cout << k - j;break; }
						else {
							continue;
						}
					}
					if (k == masu[0].size()) cout << k - j;
					j = k-1;
				}
			}
			if (i != masu.size() - 1)cout << "/";
		}
		cout << endl;
	}
}