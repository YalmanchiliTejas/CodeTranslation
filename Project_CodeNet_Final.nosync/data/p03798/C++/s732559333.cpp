#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 13;

int n;
char res[N];
string s;
map<char, char> rh;

bool check()
{
	for (int i = 1; i < n - 2; i ++ )
		if (res[i] == 'S')  // sheep
		{
			if (s[i] == 'o') res[i + 1] = res[i - 1];
			else res[i + 1] = rh[res[i - 1]];
		}
		else  // wolf
		{
			if (s[i] == 'x') res[i + 1] = res[i - 1];
			else res[i + 1] = rh[res[i - 1]];
		}
		
	for (int i = n - 2; i < s.size(); i ++ )
		if (res[i] == 'S')
		{
			if (s[i] == 'o' && res[i - 1] != res[(i + 1) % n]) return false;
			else if (s[i] == 'x' && res[i - 1] == res[(i + 1) % n]) return false;
		}
		else
		{
			if (s[i] == 'x' && res[i - 1] != res[(i + 1) % n]) return false;
			else if (s[i] == 'o' && res[i - 1] == res[(i + 1) % n]) return false;
		}
	return true;
}

bool solve(char c)
{
	memset(res, 0, sizeof res);
	res[0] = c;
	if (c == 'S')  // sheep
	{
		if (s[0] == 'o')  // same
		{
			res[1] = res[n - 1] = 'S';
			if (check()) return true;
			res[1] = res[n - 1] = 'W';
			if (check()) return true;
		}
		else  // dif
		{
			res[1] = 'W', res[n - 1] = 'S';
			if (check()) return true;
			res[1] = 'S', res[n - 1] = 'W';
			if (check()) return true;
		}
	}
	else  // wolf
	{
		if (s[0] == 'o')  // dif
		{
			res[1] = 'W', res[n - 1] = 'S';
			if (check()) return true;
			res[1] = 'S', res[n - 1] = 'W';
			if (check()) return true;
		}
		else  // same
		{
			res[1] = res[n - 1] = 'S';
			if (check()) return true;
			res[1] = res[n - 1] = 'W';
			if (check()) return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> s;
	
	rh['W'] = 'S', rh['S'] = 'W';
	
	if (solve('S') || solve('W')) cout << res << endl;
	else puts("-1");
	return 0;
}