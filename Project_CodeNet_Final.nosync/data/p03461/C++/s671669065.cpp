#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 29;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}


int main() {
  int A, B, D[10][10];
  cin >> A >> B;
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < B; j++) {
      cin >> D[i][j];
    }
  }

  int F[101][101] = {{}};
  for(int a = 0; a <= 100; a++) {
    for(int b = 0; b <= 100; b++) {
      for(int c = 0; c < A; c++) {
        for(int d = 0; d < B; d++) {
          F[a][b] = max(F[a][b], D[c][d] - a * (c + 1) - b * (d + 1));
        }
      }
    }
  }

  for(int c = 1; c <= A; c++) {
    for(int d = 1; d <= B; d++) {
      WeightedGraph< int > g(202);
      for(int a = 0; a <= 99; a++) {
        g[a].emplace_back(a + 1, c);
        g[a + 102].emplace_back(a + 101, d);
      }
      for(int a = 0; a <= 100; a++) {
        for(int b = 0; b <= 100; b++) {
          g[a].emplace_back(b + 101, F[a][b]);
        }
      }
      if(dijkstra(g, 0)[101] != D[c - 1][d - 1]) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }


  Edges< int > edges;
  for(int a = 0; a <= 99; a++) {
    edges.emplace_back(a, a + 1, -1);
    edges.emplace_back(a + 102, a + 101, -2);
  }
  for(int a = 0; a <= 100; a++) {
    for(int b = 0; b <= 100; b++) {
      edges.emplace_back(a, b + 101, F[a][b]);
    }
  }
  cout << "Possible" << endl;
  cout << 202 << " " << edges.size() << endl;
  for(auto &e : edges) {
    cout << e.src + 1 << " " << e.to + 1 << " ";
    if(e.cost == -1) cout << "X" << endl;
    else if(e.cost == -2) cout << "Y" << endl;
    else cout << e.cost << endl;
  }
  cout << 1 << " " << 102 << endl;
}

