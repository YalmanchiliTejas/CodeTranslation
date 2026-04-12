#include "bits/stdc++.h"
using namespace std;

string l("qwertasdfgzxcvb");

int main() {
	while (1) {
		string st; cin >> st;
		if (st == "#") {
			break;
		}
		else {
			bool a = true;
			int ans = 0;
			for (int i = 0; i < st.size(); ++i) {
				if ((l.find(st[i]) != string::npos) != a&&i != 0) {
					ans++;
				}
				if (l.find(st[i])!=string::npos) {
					a = true;
				}
				else {
					a = false;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}