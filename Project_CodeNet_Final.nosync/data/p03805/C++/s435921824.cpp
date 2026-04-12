#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

/*
__attribute__((constructor))
void initial()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}
*/
int edge[8][8];

int DFS(int index, int N, int value)
{
	//cout << index << endl;
	int sum = 0;

	if (value == 0)
	{
		return 1;
	}

	for (int i = 0; i < N; i++)
	{
		if ((edge[index][i] == 1) &&  ((value & (1 << i)) != 0))
		{
			sum += DFS(i, N, value & (~(1 << i)));
		}
	}
	return sum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	
	cin >> N >> M;

	#if 0
	//vector< pair<int, int> > edgy;
	map<int, std::vector<int> > edge;
	rep(i, M)
	{
		int a, b;
		cin >> a >> b;
		if (edge.find(a) == edge.end())
		{
			std::vector<int> v;
			v.pb(b);
			edge[a] = v;
		}
		else
		{
			edge[a].pb(b);
		}

		if (edge.find(b) == edge.end())
		{
			std::vector<int> v;
			v.pb(a);
			edge[b] = v;
		}
		else
		{
			edge[b].pb(a);
		}
	}
	#endif

	memset(edge, 0, sizeof(edge));

	rep(i, M)
	{
		int a, b;
		cin >> a >> b;
		edge[a-1][b-1] = 1;
		edge[b-1][a-1] = 1;
	}

	cout << DFS(0, N, (1 << N) - 1 - 1) << endl;

	return 0;
}
