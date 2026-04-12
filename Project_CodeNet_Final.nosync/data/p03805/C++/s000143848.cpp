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
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////

int N, M;
int G[10][10];
bool visited[10];
int ans = 0;

int main() {
	cin >> N >> M;
	memset(G, 0, sizeof(G));
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	vector<int>v;
	int res = 0;
	for (int i = 1; i < N; ++i)v.push_back(i);
	sort(v.begin(), v.end());
	do {
		int now = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (G[now][v[i]] == 0)break;
			now = v[i];
			if (i == v.size() - 1)res++;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << res << endl;
	return 0;

}