#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>

#define	MOD 1000000007;
#define PI 3.14159265358979323846;

using namespace std;
typedef long long ll;
#define	MAX_NODE 8;

#define WHITE 0;
#define GRAY 1;
#define BLACK 2;

int P[9][9];

int N;
int totalCount = 0;
void dfs(int nodeID, int nodeCount, int color[])
{
	//cout << nodeID << endl;
	color[nodeID] = 2;
	if (nodeCount == N)
	{
		totalCount++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (P[nodeID][i] == 1 && color[i] == 0)
		{
			dfs(i, ++nodeCount, color);
			color[i] = 0;
			nodeCount--;
		}
	}
}

int main()
{
	int  M;
	cin >> N >> M;
	int color[9];
	for (int i = 1; i <= N; i++)
	{
		color[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int n, m;
		cin >> n >> m;
		P[n][m] = 1;
		P[m][n] = 1;
	}

	dfs(1, 1, color);
	cout << totalCount << endl;
	return 0;
}