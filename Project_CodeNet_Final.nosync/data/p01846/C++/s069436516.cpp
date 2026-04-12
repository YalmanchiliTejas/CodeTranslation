#include <bits/stdc++.h>
using namespace std;
string s; int a, b, c, d;
int main() {
	while(cin >> s, s != "#") {
		cin >> a >> b >> c >> d; s += '/'; a--, b--, c--, d--;
		int pre = 0; vector<string> t;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '/') {
				t.push_back(s.substr(pre, i - pre));
				pre = i;
			}
		}
		vector<vector<int> > v(t.size());
		for(int i = 0; i < t.size(); i++) {
			for(int j = 0; j < t[i].size(); j++) {
				if(t[i][j] == 'b') v[i].push_back(1);
				else for(int k = 0; k < t[i][j] - 48; k++) v[i].push_back(0);
			}
		}
		v[a][b] = 0; v[c][d] = 1;
		for(int i = 0; i < v.size(); i++) {
			if(i) cout << '/';
			string ret; int pre2 = 0; v[i].push_back(-1);
			for(int j = 1; j < v[i].size(); j++) {
				if(v[i][j] != v[i][j - 1]) {
					if(v[i][j - 1] == 0) ret += (j - pre2) + 48;
					pre2 = j;
				}
				if(v[i][j - 1] == 1) ret += 'b';
			}
			cout << ret;
		}
		cout << endl;
	}
	return 0;
}