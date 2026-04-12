// ??¨

#include<algorithm>
#include<functional>
#include<vector>

using Size = int;
using Vertex = int;
using Weight = long long;
struct Edge {Vertex from, to; Weight weight;};
using Graph = std::vector<std::vector<Edge>>;

// ????????? O(|V| + |E|)
Vertex farthest(const Graph& G, Vertex v) {
  std::vector<Weight> d(G.size());
  std::function<Vertex(Vertex, Vertex)> dfs = [&](Vertex cur, Vertex pre) {
    auto res = cur;
    for(const auto& e: G[cur]) if(e.to != pre) {
      auto nex = dfs(e.to, e.from);
      auto w = e.weight + d[e.to];
      if(w <= d[cur]) continue;
      d[cur] = w;
      res = nex;
    }
    return res;
  };
  return dfs(v, -1);
}

// ???????????? O(|V| + |E|)
std::pair<Vertex, Vertex> farthest(const Graph& G) {
  auto v = farthest(G, 0);
  return std::make_pair(v, farthest(G, v));
}

// ?????? (????????????????????§????????¢) O(|V| + |E|)
Weight height(const Graph& G, Vertex v) {
  std::vector<Weight> d(G.size());
  std::function<Weight(Vertex, Vertex)> dfs = [&](Vertex cur, Vertex pre) {
    for(const auto& e: G[cur]) if(e.to != pre) d[cur] = std::max(d[cur], e.weight + dfs(e.to, e.from));
    return d[cur];
  };
  return dfs(v, -1);
}

// ??´??? O(|V| + |E|)
Weight diameter(const Graph& G) {
  return height(G, farthest(G, 0));
}

// ?????§??¬????????? O(|V| + |E|)
//   (??????) source ??¨????????£?????????????????????, ?????§??¬????????????????????°?????????
Size maximum_independent_set(const Graph& G, Vertex source = 0) {
  std::vector<std::vector<Size>> dp(2, std::vector<Size>(G.size(), -1));
  std::function<Size(bool, Vertex, Vertex)> dfs = [&](bool opt, Vertex cur, Vertex pre) {
    if(~dp[opt][cur]) return dp[opt][cur];
    dp[opt][cur] = opt ? 1 : 0;
    for(const auto& e: G[cur]) if(e.to != pre) {
      if(opt) dp[opt][cur] += dfs(false, e.to, e.from);
      else    dp[opt][cur] += std::max(dfs(false, e.to, e.from), dfs(true, e.to, e.from));
    }
    return dp[opt][cur];
  };
  return std::max(dfs(false, source, -1), dfs(true, source, -1));
}

// Heavy Light Decomposition
//   ??????: https://blog.anudeep2011.com/heavy-light-decomposition/
//   ?§????: O(|V| + |E|)
//   LCA:  O(log |V|)
class HeavyLightDecomposition {
 public:
  HeavyLightDecomposition(const Graph& G, Vertex root) : chain(G.size()), position(G.size()), parent(G.size(), NIL), depth(G.size(), NIL), subsize(G.size()) {
    // construct a tree
    std::function<Size(Vertex, Size)> dfs = [&](Vertex cur, Size d) {
      depth[cur] = d;
      subsize[cur] = 1;
      for(const auto& e: G[cur]) if(depth[e.to] == NIL) {
        parent[e.to] = e.from;
        subsize[cur] += dfs(e.to, d+1);
      }
      return subsize[cur];
    };
    // HLD
    std::function<Size(Vertex, Size)> HLD = [&](Vertex cur, Size id) {
      // add to a chain
      if(head.size() <= id) {
        head.emplace_back(cur);
        size.emplace_back(0);
      }
      chain[cur] = id;
      position[cur] = size[id];
      ++size[id];
      // find the special child
      auto max = 0, nex = 0;
      for(const auto& e: G[cur]) if(e.from == parent[e.to]) if(subsize[e.to] > max) {
        max = std::max(max, subsize[e.to]);
        nex = e.to;
      }
      // if cur is not a leaf
      if(max > 0) id = HLD(nex, id);
      // normal childs
      for(const auto& e: G[cur]) if(e.from == parent[e.to]) if(e.to != nex) id = HLD(e.to, id+1);
      return id;
    };
    // initialize
    dfs(root, 0);
    HLD(root, 0);
  }
  Vertex lca(Vertex u, Vertex v) const {
    while(head[chain[u]] != head[chain[v]]) {
      if(depth[head[chain[u]]] > depth[head[chain[v]]]) std::swap(u, v);
      v = parent[head[chain[v]]];
    }
    return depth[u] < depth[v] ? u : v;
  }
 private:
  const Size NIL = -1;
  std::vector<Vertex> head;
  std::vector<Size> chain, position, size;
  std::vector<Vertex> parent;
  std::vector<Size> depth, subsize;
};

#include<bits/stdc++.h>
using namespace std;

// ?????? (????????????????????§????????¢) (?????¢???) O(|V| |E|)
Weight height(const Graph& G, Vertex u, auto i, auto& memo) {
  if(~memo[u][i]) return memo[u][i];
  memo[u][i] = G[u][i].weight;
  auto v = G[u][i].to;
  for(auto j = 0; j < G[v].size(); ++j) if(G[v][j].to != u) {
    memo[u][i] = max(memo[u][i], G[u][i].weight + height(G, v, j, memo));
  }
  return memo[u][i];
}

int main() {
  int n;
  cin >> n;
  Graph G(n);
  vector<vector<Weight>> memo(n);
  for(auto i = 1; i < n; ++i) {
    Vertex s, t; Weight w;
    cin >> s >> t >> w;
    G[s].push_back({s, t, w});
    G[t].push_back({t, s, w});
    memo[s].emplace_back(-1);
    memo[t].emplace_back(-1);
  }
  vector<Weight> res(n);
  for(auto u = 0; u < n; ++u) {
    for(auto i = 0; i < G[u].size(); ++i) res[u] = max(res[u], height(G, u, i, memo));
    cout << res[u] << endl;
  }
}