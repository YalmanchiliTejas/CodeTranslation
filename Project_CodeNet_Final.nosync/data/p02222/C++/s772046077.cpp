#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 998244353
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;
typedef pair<llint, llint> P;

int n;
vector<llint> G[100005];
map<P, llint> mp;
int dif[100005];

int parent[500005];
llint dp[500005], dp2[500005];

const llint e = 0; //
llint ope(llint a, llint b)
{
	return max(a, b); //
}

llint get(int u, int v)
{
	if(parent[u] == v) return dp2[u];
	else return dp[v];
}

void dfs(int v, int p)
{
	parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	llint sum = e;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(u == p) continue;
		sum = ope(sum, get(v, u)); //
	}
	dp[v] = sum+1; //
}

llint lsum[500005], rsum[500005];
void dfs2(int v, int p)
{
	llint m = G[v].size(), sum;
	
	sum = lsum[0] = e;
	for(int i = 0; i < m; i++){
		int u = G[v][i];
		sum = ope(sum, get(v, u)); //
		lsum[i+1] = sum;
	}
	sum = rsum[m+1] = e;
	for(int i = m-1; i >= 0; i--){
		int u = G[v][i];
		sum = ope(sum, get(v, u)); //
		rsum[i+1] = sum;
	}
	for(int i = 0; i < m; i++){
		if(G[v][i] == p) continue;
		dp2[G[v][i]] = ope(lsum[i], rsum[i+2])+1; //
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1);
	dfs2(1, -1);
	
	/*for(auto it = mp.begin(); it != mp.end(); it++){
		cout << it->first.first << " " << it->first.second << " " << it->second << endl;
	}*/
	
	vector<llint> vec;
	for(int i = 1; i <= n; i++){
		if(G[i].size() < 3) continue;
		vec.clear();
		for(int j = 0; j < G[i].size(); j++){
			vec.push_back(get(i, G[i][j]));
		}
		sort(vec.rbegin(), vec.rend());
		llint x = vec[0], y = vec[2], l, r;
		//cout << i << " " << x << " " << y << endl;
		if(y == 0 || x+y < 3) continue;
		
		if(x > y) l = 3, r = x+y;
		else l = 3, r = 2*x-1;
		dif[l]++, dif[r+1]--;
	}
	
	llint sum = 0;
	for(int i = 1; i <= n; i++){
		sum += dif[i];
		if(sum) cout << 0;
		else cout << 1;
	}
	cout << endl;

	return 0;
}

