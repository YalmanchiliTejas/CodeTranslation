#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

int main()
{
	// a, b, c, d, e
	// f, g, h, i, j
	// k, l, m, n, o
	// p, q, r, s, t
	// u, v, w, x, y
	// z
	bool alp[26] = { 0, 0, 0, 0, 0,
					 0, 0, 1, 1, 1,
					 1, 1, 1, 1, 1,
					 1, 0, 0, 0, 0,
					 1, 0, 0, 0, 1,
					 0 };
	string str;
	while (cin >> str, str != "#") {
		bool prev = alp[str[0] - 'a'];
		int ans = 0;
		REP(i, 1, str.size()) {
			bool now = alp[str[i] - 'a'];
			if (prev != now) ans++;
			prev = now;
		}

		cout << ans << endl;
	}
	return 0;
}