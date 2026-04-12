#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);


string s[11];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int h, w;
	cin >> h >> w;
	int cn = 0;
	for (int i = 0; i < h; i++)
	{
		cin >> s[i];
		for (int j = 0; j < w; j++)
		{
			if (s[i][j] == '#') cn++;
		}
		s[i] += '.';
	}
	s[h].resize(w, '.');
	if (cn != h + w - 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	int x = 0, y = 0;
	while ((x < h - 1) || (y < w - 1))
	{
		if (s[x + 1][y] == s[x][y + 1])
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if (s[x + 1][y] == '#') x++;
		else y++;
	}
	cout << "Possible" << endl;
	return 0;
}




