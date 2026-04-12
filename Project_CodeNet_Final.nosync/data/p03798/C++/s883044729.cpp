#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//https://atcoder.jp/contests/abc055/tasks/arc069_b

//	ss	sw	ws	ww
//o	s	w	w	s
//x	w	s	s	w

//	00	01	10	11
//0	0	1	1	0
//1	1	0	0	1

int n;
string s;
bool c[100000];

int main() {
	cin >> n >> s;
	for (int a = 0; a < 2; ++a)
		for (int b = 0; b < 2; ++b) {
			c[0] = a;
			c[1] = b;
			for (int i = 2; i < n; ++i)
				c[i] = c[i - 2] ^ c[i - 1] ^ (s[i - 1] == 'x');
			if ((c[n - 1] ^ c[0] ^ c[1] ^ (s[0] == 'x'))
					|| (c[n - 2] ^ c[n - 1] ^ c[0] ^ (s[n - 1] == 'x')))
				continue;
			else {
				for (int i = 0; i < n; ++i)
					cout << (c[i] ? 'W' : 'S');
				cout << endl;
				return 0;
			}
		}
	cout << -1 << endl;
}
