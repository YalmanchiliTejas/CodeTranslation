#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>
#include<utility>
#include<map>
#include <queue>
#include <set>

using namespace std;


int main(){
	int n, cnt[50][26]{},m[26];
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			cnt[i][s[j] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		m[i] = 999999;
		for (int j = 0; j < n; j++) {
			m[i] = min(m[i], cnt[j][i]);
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < m[i]; j++) {
			char c ='a' + i;
			cout << c;
		}
	}
	cout << endl;
 	return 0;
}

