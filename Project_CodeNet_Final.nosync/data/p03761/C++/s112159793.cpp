#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> S, T;

int main(void) {
	string str, ans;

	S.resize(26, 50);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		T.clear();
		T.resize(26, 0);
		for (int p = 0; p < (int)str.length(); ++p)
			++T[(int)(str[p] - 'a')];
		for (int c = 0; c < 26; ++c) {
			if (S[c] == 0)
				continue;
			if (T[c] < S[c])
				S[c] = T[c];
		}
	}
	ans = "";
	for (int c = 0; c < 26; ++c) {
		if (S[c] != 0)
			ans += string(S[c], 'a' + (char)c);
	}

	cout << ans << '\n';
	return 0;
}
