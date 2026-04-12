#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include <queue>
#include <string>
#include <set>

typedef  long long lol;
using namespace std;

#define fori(i,j,k) for (int (i)=(j);(i) < (k);(i)++)
#define MOD 1000000007
#define EPS 0.000000001

int dsu[1000000];
int find(int x)
{
	if (dsu[x] == x)
		return x;
	return dsu[x] = find(dsu[x]);
}

void unite(int a, int b)
{
	dsu[find(a)] = find(b);
}


int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		dsu[i] = i;

	vector<pair<int, int>> xx, yy;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		xx.push_back({ x,i });
		yy.push_back({ y,i });
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());

	vector < pair<int, pair<int, int>>> dists;
	for (int j = 1; j < xx.size(); j++)
	{
		dists.push_back({ xx[j].first - xx[j - 1].first, {xx[j].second,xx[j - 1].second} });
		dists.push_back({ yy[j].first - yy[j - 1].first,{ yy[j].second,yy[j - 1].second } });
	}

	int resp = 0;
	sort(dists.begin(), dists.end());
	for (auto x : dists)
	{
		if (find(x.second.first) != find(x.second.second))
		{
			resp += x.first;
			unite(x.second.first, x.second.second);
		}
	}

	cout << resp;
	return 0;
}