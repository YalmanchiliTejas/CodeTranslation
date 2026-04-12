#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000

using namespace std;
bool dp[9][9];

int dfs(int st, int n, bool visited[]) {
	bool all_visited = false;
	int ret = 0;
	visited[st] = true;

	FOR(i, 1, n) {
		if (visited[i] == false) {
			break;
		}
		if (i == n) {
			all_visited = true;
		}
	}

	if (all_visited == true) {
		visited[st] = false;
		return 1;
	}

	FOR(i, 1, n) {
		if (visited[i] == false && dp[st][i] == true) {
			ret+=dfs(i, n, visited);
		}
	}

	if (all_visited == true) {
		ret++;
	}
	visited[st] = false;
	return ret;
	

	
}

int main(void) {
	int n, m;

	cin >> n >> m;

	FOR(i, 0, 8) {
		FOR(t, 0, 8) {
			dp[i][t] = false;
		}
	}
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		dp[a][b] = dp[b][a] = true;
	}
	
	bool visited[9];
	FOR(i, 0, 8) {
		visited[i] = false;
	}


	cout << dfs(1, n, visited) << endl;

	return 0;
}