#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <bitset>
#include <map>
#include <cstring>
#include <cstdlib>

#define INF_LL 9000000000000000000
#define INF 2000000000

#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

class Union_find{
private:
	vector<int> par;
	vector<int> rank;
	int n;

public:
	Union_find(int a){
		n = a;
		for(int i = 0;i < n;i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int flag[10] = {};
int N, M;
vector<int> G[9];

int dfs(int x, int be, int cnt){
	if(cnt == N) return 1;
	
	ll res = 0;
	REP(i, G[x].size()){
		if(flag[G[x][i]]) continue;
		flag[G[x][i]] = true;
		res += dfs(G[x][i], x, cnt+1);
		flag[G[x][i]] = false;
	}
	return res;
}

int main(void){
	cin >> N >> M;
	REP(i, M){
		int a, b;
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	flag[0] = true;
	cout << dfs(0, -1, 1) << endl;
}
