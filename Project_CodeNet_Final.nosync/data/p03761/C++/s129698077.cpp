
// C - 怪文書

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

string S[50];

int count_char(char c, string S) {
	int result = 0;
	for (int i=0; i<S.size(); i++) {
		if (S[i] == c) result++;
	}
	return result;
}

int main() {
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> S[i];
		sort(S[i].begin(), S[i].end());
	}

	string ans = "";
	for (char c = 'a'; c <= 'z'; c++) {
		int cnt = INF;
		for (int i=0; i<n; i++) {
			cnt = min(cnt, count_char(c, S[i]));
		}
		for (int i=0; i<cnt; i++) {
			ans += c;
		}
	}

	cout << ans << endl;

	return 0;
}