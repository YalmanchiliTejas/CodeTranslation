#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
using namespace __gnu_pbds;
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using pl = pair<ll, ll>;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll n;

vector<pl> v, u;

struct Edge {
  ll w, from, to;
};

vector<Edge> edges;

bool cmp(Edge a, Edge b) {
  return a.w < b.w;
}


ll parent[111111], rang[111111];

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rang[a] < rang[b])
			swap (a, b);
		parent[b] = a;
		if (rang[a] == rang[b])
			++rang[a];
	}
}

int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);

  for (int i = 0; i < 111111;i++) {
	  parent[i] = i;
  }

  cin >> n;
  v.resize(n);
  u.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> u[i].first;
    v[i].second = u[i].second = i;
  }

  ll anw = 0;

  sort(all(v));
  sort(all(u));

  for (int i = 1; i < n; i++) {
    ll vdist = v[i].first-v[i-1].first;
    ll udist = u[i].first-u[i-1].first;
    edges.push_back({vdist, v[i].second, v[i-1].second});
    edges.push_back({udist, u[i].second, u[i-1].second});
  }


  sort(all(edges), cmp);


  for (Edge e: edges) {
    if (find_set(e.from) != find_set(e.to)) {
      union_sets(e.from, e.to);
      anw += e.w;
    }
  }

 

  cout << anw << endl;
}