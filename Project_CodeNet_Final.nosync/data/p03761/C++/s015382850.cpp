#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int main() {
	int n;
	cin >> n;
	
	int tmp_cnt[26], min_cnt[26];
	for (int i = 0; i < 26; i++) {
		tmp_cnt[i] = 0;
		min_cnt[i] = INF;
	}

	string S;
	for (int i = 0; i < n; i++) {
		cin >> S;
		for (auto c : S) tmp_cnt[c - 'a']++;
		for (int i = 0; i < 26; i++) {
			min_cnt[i] = min(min_cnt[i], tmp_cnt[i]);
			tmp_cnt[i] = 0;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < min_cnt[i]; j++) {
			cout << (char)('a'+i);
		}
	}
	cout << endl;
}
