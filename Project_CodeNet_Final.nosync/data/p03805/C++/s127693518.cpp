// #include <bits/stdc++.h>
#include <map>
#include <set>
#include <ctime>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define mod 1000000007
#define INF 1000000000

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(x) begin(x), end(x)
#define len(x) ((int)(x).size())
#define contains(a, x) (a.find(x) != end(a))
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); ++i)
#define RF(i,a,b)for(int i = (int)(a); i >= (int)(b); --i)

using dbl = double;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvl = vector<long long>;
using pi = pair<int,int>;

#define fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define log(x) cout << (x) << endl;



int n,m,a,b;
set<int> seen;
map<int,vi> graph;

int dfs(int v) {
	if (len(seen) == n)
		return 1;

	int res = 0;
	for (auto node: graph[v]) {
		if (contains(seen, node))
			continue;
		seen.emplace(node);
		res += dfs(node);
		seen.erase(node);
	}

	return res;
}

int main() {
	cin>>n>>m;

	rep (i, m) {
		cin>>a>>b;
		graph[a].eb(b);
		graph[b].eb(a);
	}

	seen.emplace(1);
	log(dfs(1));

	return 0;
}



