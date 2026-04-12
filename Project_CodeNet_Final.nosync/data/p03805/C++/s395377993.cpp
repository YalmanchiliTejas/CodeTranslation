#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <cstring>
#include <map> 
#include<set>
#include<queue>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
const ll inf = -1e18;
typedef pair<ll, ll> P;
ll ma = 1000000000 + 7;
ll mx = 1000003;
ll h, w, n,m,k; string s,t;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll x, ll y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);

}
ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
void comb(vector<vector <ll> >& v) {
	for (ll i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (ll k = 1; k < v.size(); k++) {
		for (int j = 1; j < k; j++) {
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j])%ma;
		}
	}
}

ll GetDigit(ll num) {
	return log10(num) + 1;
}

bool graph[8][8];
const int nmax = 8;
ll res;
int dfs(int v, int N, bool visited[nmax]) {
		bool all_visited = true;
		for (int i = 0; i < N; ++i) {
		if (visited[i] == false)
		 all_visited = false;
		}
		if (all_visited) {
		return 1;
		}
		int ret = 0;
		for (int i = 0; i < N; ++i) {
		if (graph[v][i] == false) continue;
		if (visited[i]) continue;
			visited[i] = true;
			ret += dfs(i, N, visited);
			visited[i] = false;
		}
		return ret;
}
int main() {
	cin >> n >> m;
	res = 0;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	bool seen[8];
	rep(i, n) {
		seen[i] = false;
	}
	seen[0] = true;
	cout << dfs(0,n,seen) << endl;
}
