#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include<bitset>

using namespace std;
#define loop(i,n) for(int i = 0; i < (n); ++i)
#define loops(i,f,n) for(int i = (f); i < (n); ++i)
#define INF 9999999
#define in(a) cin>>a
#define out(a) cout<<a<<endl

bool graph[10][30];

int dfs(int v, int n, bool visited[10])//v=今見てる頂点のインデックス　n=ノードの数　visited[]=それまでどの頂点を訪れたかを記録した配列
{
	bool all_visited = true;
	loop(i, n)
	{
		if (visited[i] == false)all_visited = false;//全て訪れているかを調べる
	}
	if (all_visited)return 1;//パスが見つかれば1を返す

	int ret = 0;

	loop(i, n)//すべての頂点に対して
	{
		if (graph[v][i] == false)continue;
		if (visited[i])continue;
		//グラフが繋がっている、かつ未訪問ならば
		visited[i] = true;//訪問済みにする
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;

	loop(i, m)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}

	bool visited[10];
	loop(i, n)visited[i] = false;

	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}