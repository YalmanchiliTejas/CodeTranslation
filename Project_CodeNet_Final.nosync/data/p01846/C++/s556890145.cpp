#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	while (1) {
		string s; cin >> s;
		if (s == "#")break;

		vector<vector<int>>jfen(10);
		int k = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'b') {
				jfen[k].push_back(1);
			}
			else if (s[i] == '/') {
				k++;
			}
			else {
				int n = s[i] - '0';
				for (int j = 0; j < n; j++) {
					jfen[k].push_back(0);
				}
			}
		}

		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		swap(jfen[a][b], jfen[c][d]);

		for (int i = 0; i <= k; i++) {
			int cnt = 0;
			for (int j = 0; j < jfen[i].size(); j++) {
				if (jfen[i][j]) {
					if (cnt) cout << cnt;
					cnt = 0;
					cout << "b";
				}
				else {
					cnt++;
				}
			}
			if (cnt)cout << cnt;
			if(i<k)cout << "/";
		}
		cout << endl;
	}

    return 0;
}