#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
struct Edge {
  int a, b, cost;
  bool operator < (const Edge d) const {
    return (cost < d.cost);
  }
};

typedef pair <int , int> Pi;

struct UF {
  
  int parent[100005];
  
  UF()
  {
    for(int i = 0; i < 100005; i++) {
      parent[i] = i;
    }
  }

  bool unite(int a, int b)
  {
    a = getp(a); b = getp(b);
    if(a == b) return (true);
    parent[b] = a;
    return (false);
  }

  int getp(int x)
  {
    if(parent[x] == x) return (x);
    return (parent[x] = getp(parent[x]));
  }
};
int n;

Pi ynear[100005], xnear[100005];
vector < Edge > ed;
UF tree;
main()
{
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ynear[i] = Pi(y, i);
    xnear[i] = Pi(x, i);
  }

  sort(ynear, ynear + n);
  sort(xnear, xnear + n);

  for(int i = 0; i < n - 1; i++) {
    ed.push_back( (Edge) { ynear[i].se, ynear[i + 1].se, ynear[i + 1].fi - ynear[i].fi } );
    ed.push_back( (Edge) { xnear[i].se, xnear[i + 1].se, xnear[i + 1].fi - xnear[i].fi } );
  }

  sort(ed.begin(), ed.end());
  int sum = 0;
  for(int i = 0; i < ed.size(); i++) {
    if(!tree.unite(ed[i].a, ed[i].b)) {
      sum += ed[i].cost;
    }
  }

  cout << sum << endl;
  return (0);
}