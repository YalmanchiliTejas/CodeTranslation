#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>

using ll = long long;
typedef std::pair<int, int>p;

ll min(ll a, ll b) {
	if (a >= b)return b;
	else return a;
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll Z = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
bool flag = true;
bool fl = true;
bool used[210];
bool graph[100][100] = { false };
bool visited[8];
int n, m, a[50], b[50];

int dfs(int v,int n,bool visited[8]) {
	flag = true;
	for (int i = 0;i < n;i++) {
		if (visited[i] == false) {
			flag = false;
		}
	}
		if (flag) {
			return 1;
		}
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (graph[v][i] == false)continue;
			if (visited[i])continue;
			visited[i] = true;
			ans += dfs(i, n, visited);
			visited[i] = false;
		}
		return ans;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0;i < m;i++) {
		std::cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
	}
	for (int i = 0;i < n;i++) {
		visited[i] = false;
	}
	visited[0] = true;
	std::cout << dfs(0, n, visited) << std::endl;
}