#include<cstdio>
#include<cstring>
#include<cmath>
#include<bitset>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<tuple>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<stack>
#include<numeric>

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define REP(i,n) for(int i = 0;i < n;i++)
#define MEM(a,b) memset(a,b,sizeof(a))

typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

int N, M;
int con[9][9];

int main() {
	IOS;	
	cin >> N >> M;
	MEM(con, false);
	REP(i, M) {
		int x, y;
		cin >> x >> y;
		con[x][y] = con[y][x] = true;
	}
	vector<int> graph(N);
	iota(graph.begin(),graph.end(),1);
	int ans = 0;
	do {
		bool ok = true;
		REP(i, N - 1) {
			if (!con[graph[i]][graph[i + 1]])ok = false;
		}
		if (ok)ans++;
	} while (next_permutation(++graph.begin(),graph.end()));
	cout << ans << endl;
}