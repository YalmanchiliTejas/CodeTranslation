#include "bits/stdc++.h"
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	string str;
	string r = "yuiophjklnm";
	bool rflag = false;

	while (true) {
		cin >> str;
		if (str == "#")break;
		int ans = 0;
		rflag = false;
		if (r.find(str[0]) != string::npos) rflag = true;

		for (int i = 1; i < str.length(); i++) {
			//cout << rflag << endl;
			if (r.find(str[i]) != string::npos) {
				if (rflag == false) {
					ans++;
					rflag = true;
				}
			}
			else {
				if (rflag == true) {
					ans++;
					rflag = false;
				}
			}
		}
		cout << ans << endl;
	}
}