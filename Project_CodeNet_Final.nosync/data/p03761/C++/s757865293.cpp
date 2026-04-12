#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define allof(v) (v).begin(), (v).end()


li cnt[55][26];

li res[26];

int main(void)
{
	li n;
	cin >> n;
	rep(i, n) {
		string s;
		cin >> s;
		for (auto && c : s) {
			cnt[i][c - 'a']++;
		}
	}
	rep(j, 26) {
		res[j] = cnt[0][j];
	}
	repp(i, 1, n) {
		rep(j, 26) {
			res[j] = min(res[j], cnt[i][j]);
		}
	}

	rep(j, 26) {
		rep(k, res[j]) {
			cout << (char)('a' + j);
		}
	}
	cout << endl;


	return 0;
}