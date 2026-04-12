#include "bits/stdc++.h"

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long LL;
typedef unsigned long UL;

using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string s;
	vector<int> abc('z' - 'a' + 1, INT_MAX);

	REP(i, n)
	{
		cin >> s;
		
		for (char j = 'a'; j <= 'z'; ++j)
		{
			abc[j - 'a'] = min((int)count(s.begin(), s.end(), j), (int)abc[j - 'a']);
		}
	}

	for (char i = 'a'; i <= 'z'; ++i)
	{
		REP(j, abc[i - 'a'])
		{
			cout << i;
		}
	}

	return 0;
}