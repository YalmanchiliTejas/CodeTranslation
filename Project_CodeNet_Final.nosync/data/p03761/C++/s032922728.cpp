#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	int n;
	cin >> n;

	vector<int> d(26, inf);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<int> v(26, 0);
		for (int j = 0; j < (int)s.size(); j++) {
			v[s[j]-'a']++;
		}

		for (int j = 0; j < 26; j++) {
			d[j] = min(d[j], v[j]);
		}
	}

	string ans = "";
	for (int i = 0; i < 26; i++) {
		if (d[i] != inf) {
			for (int j = 0; j < d[i]; j++) {
				ans += (i+'a');
			}
		}
	}

	cout << ans << endl;
    return 0;
}
