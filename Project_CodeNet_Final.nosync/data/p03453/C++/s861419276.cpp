#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define MAX 100002

int n;
int m;

int s;
int t;

vector<pair<int, long long int> > v[MAX];

queue<int> q;
vector<pair<long long int, int> > vv;

#define MOD 1000000007

void bfs(int b, vector<long long int> &dist, vector<long long int> &way) {
	dist.assign(n, -1);
	way.assign(n, 0);
	dist[b] = 0;
	q.push(b);
	way[b] = 1;
	while (!q.empty()) {
		b = q.front();
		q.pop();
		for (auto go : v[b]) {
			long long int cost = dist[b] + go.second;
			int nex = go.first;
			if (dist[nex] == -1 || dist[nex] > cost) {
				dist[nex] = cost;
				q.push(nex);
			}
		}
	}
	vv.clear();
	for (int i = 0; i < n; i++) {
		vv.push_back(make_pair(dist[i], i));
	}
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++) {
		int node = vv[i].second;
		for (auto go : v[node]) {
			int nex = go.first;
			if (dist[node] + go.second == dist[nex]) {
				way[nex] += way[node];
				if (way[nex] >= MOD) {
					way[nex] %= MOD;
				}
			}
		}
	}
}
vector<long long int> dist[2];
vector<long long int> way[2];


#define MOD 1000000007

vector<pair<int, int> > ed;
vector<long long int> len;
int main() {
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		ed.push_back(make_pair(a, b));
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		len.push_back(c);
	}
	s--;
	t--;
	bfs(s, dist[0], way[0]);
	bfs(t, dist[1], way[1]);
	long long int need = dist[0][t];
	//collison on the node
	long long int ALL = way[0][t];
	ALL *= ALL;
	ALL %= MOD;
	for (int i = 0; i < n; i++) {
		long long int sd = dist[0][i];
		long long int td = dist[1][i];
		if (sd == td&&sd + td == need) {
			long long int w = way[0][i];
			w *= way[1][i];
			if (w >= MOD)w %= MOD;
			w *= w;
			if (w >= MOD) {
				w %= MOD;
			}
			w = MOD - w;
			ALL += w;
			ALL %= MOD;
		}
	}
	//edge
	for (int i = 0; i < ed.size(); i++) {
		if (dist[0][ed[i].first]>dist[0][ed[i].second]) {
			swap(ed[i].first, ed[i].second);
		}
		int a = ed[i].first;
		int b = ed[i].second;
		if (dist[0][a] + len[i] != dist[0][b]) {
			continue;
		}
		if (dist[1][b] + len[i] != dist[1][a]) {
			continue;
		}
		if (dist[0][a] + len[i] + dist[1][b] != need) {
			continue;
		}
		if (dist[0][a] * 2LL >= need)continue;
		if (dist[1][b] * 2LL >= need)continue;
		long long int w = way[0][a];
		w *= way[1][b];

		w %= MOD;
		w *= w;
		w %= MOD;
		w = MOD - w;
		ALL += w;
		if (ALL >= MOD)ALL %= MOD;
	}
	ALL %= MOD;
	printf("%lld\n", ALL);
	return 0;
}