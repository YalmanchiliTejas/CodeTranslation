#include <bits/stdc++.h>
using namespace std;

int main()
{
	int L;
	cin >> L;
	string s, t;
	cin >> s >> t;
	if (s + t > t + s) swap(s, t);
	string tmp;
	while (L % s.size()) {
		tmp += t;
		L -= t.size();
	}
	for (int i = 0; i < (L / (int)s.size()); i++) {
		cout << s;
	}
	cout << tmp << endl;
	return 0;
}
