#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

string S;
set<char> r;

signed main()
{
	r.insert('y');
	r.insert('u');
	r.insert('i');
	r.insert('o');
	r.insert('p');
	r.insert('h');
	r.insert('j');
	r.insert('k');
	r.insert('l');
	r.insert('n');
	r.insert('m');
	while (cin >> S, S != "#")
	{
		int ans = 0;
		bool last;
		for (int i = 0; i < S.size(); i++)
		{
			bool res = r.find(S[i]) != r.end();
			if (i > 0) ans += last != res;
			last = res;
		}
		printf("%d\n", ans);
	}
	return 0;
}