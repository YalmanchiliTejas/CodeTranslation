#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()
#pragma endregion

string s;
string can;
char sw(int pos, char answer)
{
	if (can[pos] == 'S')
	{
		if (answer == 'o')return can[pos - 1];
		else
		{
			if (can[pos - 1] == 'S')return 'W';
			else return 'S';
		}
	}
	else
	{
		if (answer == 'o')
		{
			if (can[pos - 1] == 'S')return 'W';
			else return 'S';
		}
		else return can[pos - 1];
	}
}

int main()
{
	int n; cin >> n;
	cin >> s;
	s = "v" + s + "v";
	can = "SS";
	for (int i = 1; i <= n; ++i)
	{
		can += sw(i, s[i]);
	}
	if (can[0] == can[n] && can[1] == can[n + 1])
	{
		cout << can.substr(1, n) << endl;
		return 0;
	}
	can = "WS";
	for (int i = 1; i <= n; ++i)
	{
		can += sw(i, s[i]);
	}
	if (can[0] == can[n] && can[1] == can[n + 1])
	{
		cout << can.substr(1, n) << endl;
		return 0;
	}
	can = "SW";
	for (int i = 1; i <= n; ++i)
	{
		can += sw(i, s[i]);
	}
	if (can[0] == can[n] && can[1] == can[n + 1])
	{
		cout << can.substr(1, n) << endl;
		return 0;
	}
	can = "WW";
	for (int i = 1; i <= n; ++i)
	{
		can += sw(i, s[i]);
	}
	if (can[0] == can[n] && can[1] == can[n + 1])
	{
		cout << can.substr(1, n) << endl;
		return 0;
	}
	cout << -1 << endl;
}