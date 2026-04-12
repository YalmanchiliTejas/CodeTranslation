#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

char FULL;
vector<int> G[9];

int dfs(int node, char visited)
{
	int cnt = 0;

	visited |= (1 << (node - 1));
	if (visited == FULL) cnt++;

	rep(i, (int)G[node].size()) {
		int next = G[node][i];

		if ((visited & (1 << (next - 1))) == 0) {
			cnt += dfs(next, visited);
		}
	}

	return cnt;
}

int main()
{
	int N, M, a, b;

	cin >> N >> M;
	rep(i, M) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	FULL = (char)((int)(1 << N) - 1);
	cout << dfs(1, 0) << endl;

	return 0;
}
