#include <bits/stdc++.h>
using namespace std;

int h, w;
set<int> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	for(int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < w; j++) if(s[j] == '#') {
			if(st.count(i+j)) {
				cout << "Impossible";
				return 0;
			}
			st.insert(i+j);
		}
	}
	cout << "Possible";
}
