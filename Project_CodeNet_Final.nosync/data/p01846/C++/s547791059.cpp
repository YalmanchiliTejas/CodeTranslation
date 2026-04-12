
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int solve();

int main(void) {
	while (solve()) {}
	return 0;
}

int solve() {

	string str;
	int a, b, c, d;
	int w, h;


	cin >> str;
	if (str == "#") { return 0; }

	cin >> a >> b >> c >> d;

	//	まず盤面のサイズを取得する

	// height
	{
		h = 1;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == '/') h++;
	}

	//	width
	{
		string s = str.substr(0, str.find("/", 0));

		w = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'b') { w++; }
			else { w += s[i] - '0'; }
		}
	}

	//	盤面を行単位に分割する
	vector< vector< int > > v(h, vector<int>(w, 0));
	vector< string > col(h);

	{
		int pos = 0;
		for (int i = 0; i < h; i++) {
			int nextpos = str.find("/", pos+1);
			if (nextpos == string::npos) { nextpos = static_cast<int>(str.length()); }

			col[i] = str.substr(pos, nextpos - pos);

			pos = nextpos + 1;
		}
	}

	//　盤面状態を取得する
	{
		for (int i = 0; i < h; i++) 
		{
			int p = 0;
			for (int j = 0; j < col[i].length(); j++)
			{
				if (col[i][j] == 'b') 
				{
					v[i][p] = 1;
					p++;
				}
				else
				{
					p += col[i][j] - '0';
				}
			}
		}
	}

	v[a-1][b-1] = 0; v[c-1][d-1] = 1;


	//	盤面をjfen形式で出力する
	{
		for (int i = 0; i < h; i++) {
			if (i > 0) { cout << "/"; }
			int cnt = 0;
			for (int j = 0; j < w; j++) {
				if (v[i][j] == 0) {
					cnt++;
					if (j == w - 1) {
						cout << cnt;
					}
				}
				else {
					if (cnt == 0) {
						cout << "b";
					}
					else {
						cout << cnt << "b";
					}
					cnt = 0;
				}
			}
		}

		cout << endl;
	}

	return 1;
}
