#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>
#include <cctype>
#include <stack>
#include <random>
#include <list>
#include <numeric>



#define rep(i,p,q) for(ll i = p;i < q;i++)
#define ll long long

using namespace std;

vector<vector<ll>> graph;
ll n;
ll dfs(ll v, ll count, vector<ll> used) {
	if (used.size() == n) {
		return ++count;
	}
	bool deadEnd = true;
	rep(i, 0, n) {
		if (find(used.begin(), used.end(), i) == used.end()) {
			deadEnd = false;
			if (graph[v][i] > 0) {
				vector<ll> newUsed = used;
				newUsed.push_back(i);
				count = dfs(i, count, newUsed);
			}
		}
	}
	return deadEnd ? 0 : count;
}

//ABC 54
int main(void) {
	ll m;
	cin >> n >> m;
	graph = vector<vector<ll>>(n, vector<ll>(n,-1));
	rep(i, 0, m) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	ll ans = 0;
	ans += dfs(0, 0, vector<ll>(1,0));
	
	cout << ans << endl;
}