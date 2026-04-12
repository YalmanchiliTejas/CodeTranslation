#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////
int n, m;
vector<int>V;
vector<vector<int>>G(10, vector<int>(10,0));
int ans = 0;
void dfs(int a,int N) {
	if (N == n -1) {
		ans++;
		return;
	}
	if (G[a][V[N]]) {
		dfs(V[N], N + 1);
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	for (int i = 1; i < n; ++i) {
		V.push_back(i);
	}
	sort(V.begin(), V.end());
	do {
		dfs(0, 0);
	} while (next_permutation(V.begin(), V.end()));
	cout << ans << endl;
	return 0;
}