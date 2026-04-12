#include "bits/stdc++.h"

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;

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
			abc[j - 'a'] = (int)min((int)count(s.begin(), s.end(), j), abc[j - 'a']);
		}
	}

	for (size_t i = 0; i < abc.size(); ++i)
	{
		for (int j = 0; j < abc[i]; ++j)
		{
			cout << (char)('a' + i);
		}
	}

	cout << "\n";

	return 0;
}