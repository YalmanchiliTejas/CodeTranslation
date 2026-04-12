#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int n;
vector<bitset<8> > graph;

int solve(int curr, bitset<8> used)
{
	if(used.count() == n)
		return 1;

	int ans = 0;
	for(int i=0; i<n; ++i){
		if(graph[curr][i] && !used[i])
			ans += solve(i, used | bitset<8>(1 << i));
	}
	return ans;
}

int main()
{
	int m;
	cin >> n >> m;
	graph.assign(n, 0);
	for(int i=0; i<m; ++i){
		int a, b;
		cin >> a >> b;
		-- a;
		-- b;
		graph[a][b] = graph[b][a] = true;
	}

	int ans = solve(0, 1);
	cout << ans << endl;

	return 0;
}