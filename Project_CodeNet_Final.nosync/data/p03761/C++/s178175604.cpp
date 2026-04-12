#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	int min_size = 51;
	string minstr;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (min_size > s[i].size()) {
			min_size = s[i].size();
			minstr = s[i];
		}
	}
	string ans = "";
	for (int i = 0; i < min_size; i++) {// i th judge
		int count = 0;
		for (int j = 0; j < n; j++) {// j th string
			for (int k = 0; k < s[j].size(); k++) {// j th string's k th char
				if (s[j][k] == minstr[i]) {
					count++;
					s[j].erase(k, 1);
					break;
				}
			}
		}
		if (count == n)
			ans = ans + minstr[i];
	}
	sort(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}