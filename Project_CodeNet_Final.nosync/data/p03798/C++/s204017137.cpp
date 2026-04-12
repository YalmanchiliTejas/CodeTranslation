#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	pair<char, pair<char, char>> p[] = {
		{ 'S', { 'S', 'W' } },
		{ 'S', { 'W', 'S' } },
		{ 'W', { 'S', 'W' } },
		{ 'W', { 'W', 'S' } }
	};
	string t;
	cin >> t;
	for (auto &it : p) {
		bool g = true;;
		string s(n, 'l');
		s[0] = it.first;
		for (int i = 0; i < n; i++) {
			char c = t[i];
			int prev = ((i - 1) % n + n) % n;
			int next = ((i + 1) % n + n) % n;
			if (s[i] == 'W') {
				c = c == 'o' ? 'x' : 'o';
			}
			if (c == 'o') {
				if (s[prev] != s[next]
				    && s[prev] != 'l' && s[next] != 'l') {
					g = false;
					break;
				}
				if (s[prev] == 'l' && s[next] != 'l') {
					s[prev] = s[next];
				} else if (s[next] == 'l' && s[prev] != 'l') {
					s[next] = s[prev];
				} else if (s[prev] == 'l') {
					s[prev] = s[next] = it.second.first;
				}
			} else {
				if (s[prev] == s[next]
				    && s[prev] != 'l' && s[next] != 'l') {
					g = false;
					break;
				}
				if (s[prev] == 'l' && s[next] != 'l') {
					s[prev] = s[next] == 'S' ? 'W' : 'S';
				} else if (s[next] == 'l' && s[prev] != 'l') {
					s[next] = s[prev] == 'S' ? 'W' : 'S';
				} else if (s[prev] == 'l') {
					s[next] = it.second.first;
					s[prev] = it.second.second;
				}
			}
		}
		if (g) {
			cout << s << '\n';
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}

