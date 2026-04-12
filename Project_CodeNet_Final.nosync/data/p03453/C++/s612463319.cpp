#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1LL<<60)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())
#define MOD 1000000007


int n, m;
int s, t;

vector<pair<int, int>> edge[100000];

long long d1[100000];
long long cnt1[100000];
long long d2[100000];
long long cnt2[100000];

void calc1(int s, long long d[]) {
	fill_n(d, n, INF);
	priority_queue<pair<long long, int>> pq;
	pq.emplace(0, s);
	d[s] = 0;

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int u = p.second;
		if (d[u] < -p.first)continue;
		for (auto e : edge[p.second]) {
			long long c = -p.first + e.second;
			int v = e.first;
			if (d[v] == INF || c < d[v]) {
				d[v] = c;
				pq.emplace(-c, v);
			}
		}
	}
}

void calc2(int s, long long d2[], long long cnt[],long long mind) {
	fill_n(cnt, n, 0LL);
	cnt[s] = 1;
	priority_queue<pair<long long, int>> pq;
	pq.emplace(0, s);
	vector<bool> in(n, false);
	in[s] = true;

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int u = p.second;
		for (auto e : edge[p.second]) {
			long long c = -p.first + e.second;
			int v = e.first;
			if (c + d2[v] == mind) {
				if (!in[v]) {
					pq.emplace(-c, v);
					in[v] = true;
				}
				cnt[v] += cnt[u];
				cnt[v] %= MOD;
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> t;
	s--; t--;
	rep(i,m) {
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		edge[u].emplace_back(v, d);
		edge[v].emplace_back(u, d);
	}

	calc1(s, d1);
	calc1(t, d2);
	long long mind = d1[t];

	calc2(s, d2, cnt1, mind);
	calc2(t, d1, cnt2, mind);

	long long ans = cnt1[t] * cnt2[s] % MOD;
	rep(u, n)for(auto p : edge[u]) {
		int v = p.first;
		int c = p.second;
		if (d1[u]+c==d1[v] && d2[v]+c==d2[u] 
			&& max(d1[u],d2[v]) < min(d1[u],d2[v]) + c ) {

			//ans -= cnt1[u] * cnt2[v];
			ans -= cnt1[u] * cnt1[u] % MOD * cnt2[v] % MOD * cnt2[v];
			ans %= MOD;
		}
	}
	rep(u, n) if(d1[u]+d2[u]==mind && d1[u]==d2[u]){
		//ans -= cnt1[u] * cnt2[u];
		ans -= cnt1[u] *cnt1[u] % MOD * cnt2[u] % MOD * cnt2[u];
		ans %= MOD;
	}
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;



	return 0;
}