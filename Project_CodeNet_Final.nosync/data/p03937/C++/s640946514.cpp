#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>


using namespace std;

const int N = 10;
char a[N][N];
int n, m;
vector< pair<int, int> > v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '#')
			{
				v.push_back({i, j});
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1 ; i < v.size(); i++)
	{
		if (v[i].second < v[i - 1].second)
		{
			cout << "Impossible";
			exit(0);
		}
	}
	cout << "Possible";




}


 
