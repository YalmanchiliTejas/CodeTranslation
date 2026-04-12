#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const int MAX_N = 10010, MAX_V = 100010, MAX_W = 10010;

vector<int> G[MAX_V];
vector<int> C[MAX_V];

//Nは頂点、Mは辺
int N, M;
int ans = 0;
int c = 0;

//vは今の頂点の場所、nは今まで通った頂点の数、cは移動してる点の番号
void dfs(int v, int n)
{
	//すべての頂点を通ってるなら
	if (n == N)
	{
		ans++;
//		cout << endl;
		return;
	}

	//向かってる辺の数を調べる
	for (int i = 0; i < G[v].size(); i++)
	{
		bool otozure = false;
		//向かってる辺が訪れた場所か調べる
		for (int j = 0; j < C[c].size(); j++)
		{
			//向かってる辺が一つでも訪れてたなら
			if (C[c][j] == G[v][i])
			{
				otozure = true;
			}
		}

		//フラグで訪れてなければ
		if (otozure == false)
		{
			//向かってる辺に訪れたことを記録
			C[c].push_back(G[v][i]);

			vector<int> vec = C[c];

//			cout << G[v][i] << endl;

			dfs(G[v][i], n + 1);
			c++;
			copy(vec.begin(), vec.end(), back_inserter(C[c]));
			C[c].pop_back();
		}
		
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		//sはtへの辺を張る
		//無向グラフなので二つ張る
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	C[0].push_back(1);
	dfs(1, 1);

	cout << ans << endl;
}

/*

*/