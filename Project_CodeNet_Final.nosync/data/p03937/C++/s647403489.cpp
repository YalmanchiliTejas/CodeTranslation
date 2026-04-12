#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

ll dx[] = { 1, 0 };
ll dy[] = { 0, 1 };

int main()
{
	ll H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (ll i = 0; i < H; i++)
	{
		cin >> a[i];
	}
	queue<pair<ll, ll>> location;
	location.push(make_pair(0, 0));
	while (!location.empty())
	{
		pair<ll, ll> place = location.front();
		location.pop();
		ll x = place.first, y = place.second;
		a[y][x] = '.';
		for (ll i = 0; i < 2; i++)
		{
			if (x + dx[i] < W && y + dy[i] < H)
			{
				if (a[y + dy[i]][x + dx[i]] == '#')
				{
					location.push(make_pair(x + dx[i], y + dy[i]));
					break;
				}
			}
		}
	}
	for (ll i = 0; i < H; i++)
	{
		for (ll j = 0; j < W; j++)
		{
			if (a[i][j] == '#')
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}