#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
const int MAXN = (1 << 20);

string s;

void read()
{
	cin >> s;
}

void solve()
{
	bool ok = 0;
	for(int i = 0; i < (int)s.size() - 1; i++)
		if(s[i] == 'A' && s[i + 1] == 'C') ok = 1;

	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}

