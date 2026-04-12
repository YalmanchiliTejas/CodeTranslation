//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)

int n, m;
bool graph[8][8] = {};

int dfs(int v, int n, bool visited[8]) {
	bool all_visited = true;

	REP(i, n) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited == true) {
		return 1;


	}

	int ret = 0;

	REP(i, n) {
		if (graph[v][i] == true && visited[i] == false) {
			visited[i] = true;
			ret += dfs(i, n, visited);
			visited[i] = false;
		}
	}

	return ret;
}



int main() {

	
	cin >> n >> m;

	
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}

	bool visited[8] = {};

	visited[0] = true;
	cout << dfs(0, n, visited) << endl;


	return 0;
}

