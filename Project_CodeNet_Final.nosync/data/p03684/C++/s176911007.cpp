#include <bits/stdc++.h>
#define ll long long
using namespace std;

class UnionFind {
private:
  int size;
  int *par;
  int *rk;
  
public:
  UnionFind(int size) {

    this->size = size;
    par = new int[size];
    rk = new int[size];
    for(int i = 0; i < size; i++) {
      par[i] = i;
      rk[i] = 0;
    }
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(rk[x] > rk[y]) {
      par[y] = x;
    }else if(rk[x] < rk[y]){
      par[x] = y;
    }else {
      par[x] = y;
      rk[y] += 1;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int find(int x) {
    if(par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }
};

int main() {
  int N;
  cin >> N;

  vector<int> x(N), y(N);

  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  vector< pair<int, int> > x_id(N), y_id(N);

  for(int i = 0; i < N; i++) {
    x_id[i] = make_pair(x[i], i);
    y_id[i] = make_pair(y[i], i);
  }

  sort(x_id.begin(), x_id.end());
  sort(y_id.begin(), y_id.end());

  typedef pair<int, pair<int, int> > dist_nodes;

  priority_queue<dist_nodes, vector<dist_nodes>, greater<dist_nodes> > pq;

  for(int i = 0; i < N - 1; i++) {
    pq.push(make_pair(x_id[i + 1].first - x_id[i].first, make_pair(x_id[i].second, x_id[i + 1].second)));
    pq.push(make_pair(y_id[i + 1].first - y_id[i].first, make_pair(y_id[i].second, y_id[i + 1].second)));
  }

  UnionFind uf(N);

  int ans = 0;

  while(!pq.empty()) {

    dist_nodes dn = pq.top();
    pq.pop();

    int distance = dn.first;
    int node1 = dn.second.first, node2 = dn.second.second;

    if(uf.same(node1, node2)) {
      continue;
    }

    ans += distance;
    uf.merge(node1, node2);
  }

  cout << ans << endl;


}
