#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1000000007;

int main()
{
	int n, k  = 0;
	string s = "";
	cin >> n >> s >> k;
	char c = s[k - 1];

	for (int i = 0; i < s.length(); i++)
	{
		if (c != s[i])
		{
			s[i] = '*';
		}
	}

	cout << s << "\n";
	return 0;
}