#include <iostream>
#include <string>
using namespace std;

int main()
{
	int LorR[26] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 };
	string s;
	while (cin >> s, s != "#")
	{
		int ans = 0;
		for (int i = 1; i < s.size(); i++)
		{
			int now = s[i] - 'a';
			int before = s[i - 1] - 'a';
			if (LorR[now] != LorR[before]) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}