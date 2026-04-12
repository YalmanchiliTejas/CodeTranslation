#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);


int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

//素因数分解
vector<pair<ll, int>>factorize(ll n) {
	vector<pair<ll, int>>res;
	for (ll i = 2;i * i <= n;++i) {
		if (n % i)continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.emplace_back(n, 1);
	return res;
}

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]) {
	bool all_visited = true;
	for (int i = 0;i < n;++i) {
		if (visited[i] == false)all_visited = false;
	}
	if (all_visited) {
		return 1;
	}
	int ret = 0;
	rep(i, n) {
		if (graph[v][i] == false)continue;
		if (visited[i])continue;
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	bool visited[nmax];
	rep(i, n) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}
