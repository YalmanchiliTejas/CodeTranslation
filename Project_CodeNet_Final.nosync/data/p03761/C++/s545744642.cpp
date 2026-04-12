#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> S(n, "");

	string alp = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < n; i++) {
		cin >> S[i];
		sort(S[i].begin(), S[i].end());
	}

	vector<vector<int>> v(n, vector<int>(26, 0));

	for (int i = alp.length() - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			while (S[j].back() == alp[i]) {
				v[j][i] += 1;
				S[j].pop_back();
			}
		}
	}

	vector<int> d(26, 0);

	for (int i = 0; i < 26; i++) {
		d[i] = v[0][i];
	}

	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < 26; j++) {
			d[j] = min(d[j], v[i][j]);
		}
	}

	string ans = "";

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < d[i]; j++) {
			ans += alp[i];
		}
	}

	cout << ans << endl;

	return 0;
}