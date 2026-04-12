#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>
#include <complex>

using namespace std;

#define mod 1000000007

int n;
int graph[8][8] = {};
vector<vector<int> > res((1 << 8), vector<int>(8, -1));

// bit: これまで訪れたnodeの組み合わせをbitで表したもの
// now: 今いるnode
int solve(int now, int bit)
{
	// cout << now << " " << bit << endl;
	if(res[bit][now] >= 0) return res[bit][now];
	if(bit == (1 << n) - 1) return res[bit][now] = 1;
	res[bit][now] = 0;
	for(int next = 0; next < n; next++){
		if(graph[now][next] == 0 || ((1 << next) & bit) > 0) continue;
		res[bit][now] += solve(next, ((1 << next) | bit));
	}
	return res[bit][now];
}

int main()
{
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = graph[b][a] = 1;
	}
	cout << solve(0, 1) << endl;
}