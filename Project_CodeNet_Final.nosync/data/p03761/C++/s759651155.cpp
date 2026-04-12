#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;	cin>>N;
	vector<vector<int> > cnt(N, vector<int>(26, 0));
	for (int n = 0; n < N; ++n) {
		string s;	cin>>s;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			cnt[n][s[i]-'a']++;
		}
	}
	
	for (int i = 0; i < 26; ++i) {
		int shor = 100;
		for (int j = 0; j < N; ++j) {
			shor = min(shor, cnt[j][i]);
		}
		if (shor == 100)
			continue;
		for (int j = 0; j < shor; ++j)
			cout<<(char)(i+'a');
	}
	cout<<endl;
	
	return 0;
}