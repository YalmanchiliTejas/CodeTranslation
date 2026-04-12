#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

string keyboard[2] = {"qwertasdfgzxcvb", "yuiophjklnm"};

int main()
{
	while (1)
	{
		string s; cin >> s;
		if (s[0] == '#') return 0;

		int ans = 0;
		int lr;
		if (keyboard[0].find(s[0]) != string::npos)
			lr = 0;
		else
			lr = 1;

		rep(i, 1, s.length())
		{
			if (keyboard[lr].find(s[i]) == string::npos)
			{
				lr = (lr + 1) % 2;
				ans++;
			}
		}

		cout << ans << endl;
	}
}