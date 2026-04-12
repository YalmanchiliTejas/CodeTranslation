#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	string s;
	vector<int> min_cnt(26, 100000);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		vector<int> cnt(26, 0);
		for (int j = 0; j < s.size(); ++j) {
			++cnt[s[j] - 97];
		}
		for (int j = 0; j < 26; ++j) {
			min_cnt[j] = min(min_cnt[j], cnt[j]);
		}
	}
	string ans;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < min_cnt[i]; ++j) {
			ans += i + 97;
		}
	}
	cout << ans << endl;
	return 0;
}