#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <tuple>

using namespace std;
typedef long long ll;

// 素集合データ構造
struct UnionFind
{
  vector<ll> par;
  vector<ll> sizes;

  UnionFind(int n)
	: par(n)
	, sizes(n, 1LL)
  {
	for(int i = 0; i < n; i++)
	{ 
	   par[i] = i;
	}
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return sizes[find(x)];
  }
};

int main()
{
  int n;
  cin >> n;
  
  vector<pair<ll, ll>> xs;
  vector<pair<ll, ll>> ys;
  for(int i = 0; i < n; i++)
  {
	ll x, y;
	cin >> x >> y;
	xs.push_back(make_pair(x, i));
	ys.push_back(make_pair(y, i));
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  vector<tuple<ll, ll, ll>> edges;
  for(int i = 0; i < n - 1; i++)
  {
	ll diff = xs[i + 1].first - xs[i].first;
	edges.push_back(make_tuple(diff, xs[i].second, xs[i + 1].second));

	diff = ys[i + 1].first - ys[i].first;
	edges.push_back(make_tuple(diff, ys[i].second, ys[i + 1].second));
  }

  sort(edges.begin(), edges.end());
  
  UnionFind uf(n);
  int count = 0;
  ll ans = 0;
  int index = 0;
  while(index < edges.size() && count < n - 1)
  {
	ll diff, n1, n2;
	tie(diff, n1, n2) = edges[index];

	if(!uf.same(n1, n2))
	{
	  uf.unite(n1, n2);
	  count++;
	  ans += diff;
	}		
	index++;
  }
  cout << ans << endl;
    
  return 0;
}
