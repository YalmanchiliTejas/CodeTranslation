#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(){

	string n;
	int k, ans;

	cin >> n;
	cin >> k;

	if (k == 1) {
		ans = (n.size() - 1) * 9 + (int)(n[0] - '0');
		cout << ans << endl;
		return 0;
	}
	else if (k == 2) {
		if (n.size()<2) {
			cout << "0" << endl;
			return 0;
		}

		ans = (n.size() - 1)*(n.size() - 2) / 2 * 81;
		ans += ((int)(n[0] - '0') - 1)*((n.size() - 1) * 9);
		for (int i = 1;i < n.size();i++) {
			if (n[i] != '0') {
				ans += (n.size() - i - 1) * 9;
				ans += (int)(n[i]-'0');
				i=1000;
			}
		}
		cout << ans << endl;
		return 0;
	}
	else {
		if (n.size() < 3) {
			cout << "0" << endl;
			return 0;
		}

		ans= (n.size() - 1)*(n.size() - 2)*(n.size() - 3) / 6 * 81*9;
		ans += ((int)(n[0] - '0') - 1)*(n.size() - 1)*(n.size() - 2) / 2 * 81;
		for (int i = 1;i < n.size();i++) {
			if (n[i] != '0') {
				ans += (n.size() - i - 1)*(n.size() - i - 2) / 2 * 81;
				ans += ((int)(n[i] - '0') - 1)*(n.size() - i - 1) * 9;
				for (int j = i + 1;j < n.size();j++) {
					if (n[j] != '0') {
						ans += (n.size() - j - 1) * 9;
						ans += (int)(n[j]-'0');
						j=1000;
					}
				}
				i=1000;
			}
		}
		cout << ans << endl;
		return 0;
	}

}
