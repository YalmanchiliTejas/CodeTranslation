
// D - Menagerie

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

char same(char c) {
	return c;
}

char diff(char c) {
	if (c == 'S') return 'W';
	else return 'S';
}

void align(char first, char second, string& s, string& ans, int N) {
	ans[0] = first;
	ans[1] = second;
	for (int i=1; i<N-1; i++) {
		if (ans[i] == 'S') {
			if (s[i] == 'o') ans[i+1] = same(ans[i-1]);
			else ans[i+1] = diff(ans[i-1]);
		} else {
			if (s[i] == 'o') ans[i+1] = diff(ans[i-1]);
			else ans[i+1] = same(ans[i-1]);
		}
	}
}

bool verify(string& s, string& ans, int N) {
	if (ans[0] == 'S') {
		if (s[0] == 'o') {
			if (ans[N-1] != ans[1]) return false;
		} else {
			if (ans[N-1] == ans[1]) return false;
		}
	} else {
		if (s[0] == 'o') {
			if (ans[N-1] == ans[1]) return false;
		} else {
			if (ans[N-1] != ans[1]) return false;
		}
	}

	if (ans[N-1] == 'S') {
		if (s[N-1] == 'o') {
			if (ans[N-2] != ans[0]) return false;
		} else {
			if (ans[N-2] == ans[0]) return false;
		}
	} else {
		if (s[N-1] == 'o') {
			if (ans[N-2] == ans[0]) return false;
		} else {
			if (ans[N-2] != ans[0]) return false;
		}
	}

	return true;
}

int main() {
	int N;
	cin >> N;

	string s;
	cin >> s;

	string ans;
	ans.resize(N, ' ');

	// 1番目の動物が羊、2番目も羊と仮定
	align('S', 'S', s, ans, N);
	if (verify(s, ans, N)) {
		cout << ans << endl;
		return 0;
	}

	// 1番目の動物が羊、2番目は狼と仮定
	align('S', 'W', s, ans, N);
	if (verify(s, ans, N)) {
		cout << ans << endl;
		return 0;
	}

	// 1番目の動物が狼、2番目は羊と仮定
	align('W', 'S', s, ans, N);
	if (verify(s, ans, N)) {
		cout << ans << endl;
		return 0;
	}

	// 1番目の動物が狼、2番目も狼と仮定
	align('W', 'W', s, ans, N);
	if (verify(s, ans, N)) {
		cout << ans << endl;
		return 0;
	}

	// 全て矛盾
	cout << -1 << endl;
	return 0;
}
