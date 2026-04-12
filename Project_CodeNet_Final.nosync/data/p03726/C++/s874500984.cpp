#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
using namespace std;

int N;
vector<int> t[100001];
bool flg[100001];

void func(int a)
{
	int b = 0;
	for (int i = 0; i < t[a].size(); i++)
	{
		int p = t[a][i];
		if (!flg[p])
		{
			if (b == 0)
			{
				b = p;
			}
			else
			{
				return;
			}
		}
	}
	if (b > 0)
	{
		flg[a] = true;
		flg[b] = true;
		for (int j = 0; j < t[b].size(); j++)
		{
			int c = t[b][j];
			if (!flg[c])
			{
				func(c);
			}
		}
	}
}

signed main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		if (t[i].size() == 1)
		{
			func(i);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (!flg[i])
		{
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
}