#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int pa[100001];
pair<pair<int, int>, int> g[100001];
vector<pair<int, pair<int, int> > > ed;

int P(int v){
	if (pa[v])return pa[v] = P(pa[v]);
	return v;
}

inline void aded(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
	int x = abs(a.first.first - b.first.first), y = abs(a.first.second - b.first.second);
	ed.push_back(make_pair(min(x, y), make_pair(a.second, b.second)));
}

int main(){
	int n;
	scanf("%d", &n);
	f(i, 1, n + 1)scanf("%d%d", &g[i].first.first, &g[i].first.second), g[i].second = i;
	sort(g + 1, g + n + 1);
	f(i, 1, n)aded(g[i], g[i + 1]);
	f(i, 1, n + 1)swap(g[i].first.first, g[i].first.second);
	sort(g + 1, g + n + 1);
	f(i, 1, n)aded(g[i], g[i + 1]);
	sort(ed.begin(), ed.end());
	ll an = 0;
	f(i, 0, ed.size()){
		int a = P(ed[i].second.first), b = P(ed[i].second.second);
		if (a == b)continue;
		an += ed[i].first;
		pa[b] = a;
	}
	printf("%lld\n", an);
}