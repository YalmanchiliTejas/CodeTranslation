#include<iostream>
#include<cassert>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));

#define MAX_V 10

struct edge { int to, cost; }; //cost >= 0

int V, E, r; //頂点数、辺数、始点
vector<edge>G[MAX_V]; //グラフ情報
int d[MAX_V]; //最短距離

signed main() {
	cin >> V >> E;
	rep(i, E) {
		int s, t;
		edge e;
		cin >> s >> t;
		s--; t--;
		e.to = t;
		e.cost = 1;
		G[s].push_back(e);
		e.to = s;
		e.cost = 1;
		G[t].push_back(e);
	}
	vector<int>v(V - 1);
	rep(i, V - 1)v[i] = i + 1;
	int ans = 0;
	do {
		bool can = true;
		int nv = 0;
		for (int j = 0; j < V - 1; j++) {
			bool isOK = false;
			int next = v[j];
			for (int i = 0; i < G[nv].size(); i++) {
				edge e = G[nv][i];
				if (e.to == next)isOK = true;
			}
			if (!isOK)can = false;
			nv = next;
		}
		if (can)ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}