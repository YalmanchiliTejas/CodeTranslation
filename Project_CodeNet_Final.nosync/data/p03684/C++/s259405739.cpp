#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define MAX_N (100000)

using namespace std;

typedef struct {
  long to;
  long cost;
} edge;

void add_edge(vector<vector<edge>> &adj_lists, long u, long v, long cost) {
  adj_lists[u].push_back({v, cost});
  adj_lists[v].push_back({u, cost});
}

long minimum_spanning_tree(vector<vector<edge>> &adj_lists) {
  const int N = adj_lists.size();
  vector<long> ds(N, -1);
  priority_queue<pair<long, long>, vector<pair<long, long>>,
                 greater<pair<long, long>>>
      que;
  que.push(pair<long, long>(0, 0));
  long ret = 0;
  while (!que.empty()) {
    const pair<long, long> p = que.top();
    const long u = p.second, d = p.first;
    que.pop();
    // printf("u = %ld, d = %ld\n", u, d);
    if (ds[u] < 0) {
      ds[u] = d;
      ret += d;
      for (edge &e : adj_lists[u]) {
        const long v = e.to, w = e.cost;
        if (ds[v] < 0) {
          que.push(pair<long, long>(w, v));
        }
      }
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  // read inputs
  long N, xs[MAX_N], ys[MAX_N];
  scanf("%ld", &N);
  for (int i = 0; i < N; i++) {
    scanf("%ld %ld", &xs[i], &ys[i]);
  }

  // create sorted list of xs and ys
  vector<pair<long, long>> sorted_xs, sorted_ys;
  for (long i = 0; i < N; i++) {
    sorted_xs.push_back(pair<long, long>(xs[i], i));
    sorted_ys.push_back(pair<long, long>(ys[i], i));
  }
  sort(sorted_xs.begin(), sorted_xs.end());
  sort(sorted_ys.begin(), sorted_ys.end());

  // create graph where only nodes adjacent in the sorted lists are connected
  vector<vector<edge>> adj_lists(N, vector<edge>());
  for (long i = 1; i < N; i++) {
    const long u = sorted_xs[i - 1].second, v = sorted_xs[i].second;
    const long cost = min(abs(xs[u] - xs[v]), abs(ys[u] - ys[v]));
    add_edge(adj_lists, u, v, cost);
  }
  for (long i = 1; i < N; i++) {
    const long u = sorted_ys[i - 1].second, v = sorted_ys[i].second;
    const long cost = min(abs(xs[u] - xs[v]), abs(ys[u] - ys[v]));
    add_edge(adj_lists, u, v, cost);
  }

  // for (long i = 0; i < N; i++) {
  //   printf("%ld:  ", i);
  //   for (edge &e : adj_lists[i]) {
  //     const long j = e.to, w = e.cost;
  //     printf("(%ld, %ld) ", j, w);
  //   }
  //   printf("\n");
  // }

  // minimum spanning tree
  printf("%ld\n", minimum_spanning_tree(adj_lists));

  return 0;
}
