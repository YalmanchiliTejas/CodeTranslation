#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int wordcount[50][26];
	int minwordcount[26];
	int n; cin >> n;
	string s;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 26; j++) {
			wordcount[i][j] = 0;
		}
	}
	for (int j = 0; j < 26; j++) {
		minwordcount[j] = 1e9;
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			wordcount[i][s[j] - 'a']++;
		}
	}
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < n; i++) {
			minwordcount[j] = min(wordcount[i][j], minwordcount[j]);
		}
	}
	vector<char>ans;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < minwordcount[i]; j++) {
			ans.push_back((unsigned char)i + 'a');
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}