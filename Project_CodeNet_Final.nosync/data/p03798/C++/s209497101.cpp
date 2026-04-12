#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int ca = 0; ca < 4; ++ca) {
		vector<int> sw;
		sw.push_back(ca%2);
		sw.push_back(ca/2);
		for (int p = 1; p < s.length(); ++p) {
			if (sw[p] == 0) {
				if (s[p] == 'o') {
					sw.push_back(sw[p-1]);
				}
				else {
					sw.push_back(1-sw[p - 1]);
				}
			}else {
				if (s[p] == 'o') {
					sw.push_back(1-sw[p - 1]);
				}
				else {
					sw.push_back(sw[p - 1]);
				}
			}
		}
		if (sw[0] == sw[sw.size()-1]) {
			bool flag = true;
			if (s[0] == 'o' && sw[0]==0 
				|| s[0]=='x' && sw[0]==1) {
				flag = (sw[sw.size()-2] == sw[1]);
			}
			else {
				flag = (sw[sw.size()-2] != sw[1]);
			}
			if (flag) {
				for (int i = 0; i < s.length(); ++i) {
					if (sw[i] == 0) cout << "S";
					else cout << "W";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}