#include <iostream>
#include <vector>
#include <utility>
#include <assert.h>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;

#define LIMIT 1000000007

int s, t;
int vertex, path;

vector<vector<pair<LL, int> > > connection;
// node n and m are connected in a distance d
// where connection[n] = (d, m)

void shortest_path_from(int start, vector<LL>* dists) {
  vector<LL>& dist_table = *dists;
  dist_table.resize(vertex, -1);
  multimap<LL, int> q;
  q.emplace(0LL, start);
  while(!q.empty()) {
    auto iter = q.begin();
    LL d_m = iter->first;
    int m = iter->second;
    q.erase(iter);
    if(dist_table[m] != -1)
      continue;
    dist_table[m] = d_m;
    for(auto &p : connection[m]) {
      q.emplace(d_m + p.first, p.second);
    }
  }
}

vector<int> path_count1(const vector<LL>& dist_table) {
  vector<int> count_table(vertex, 0);
  count_table[s] = 1;
  multimap<LL, int> q;
  for(int i = 0; i < dist_table.size(); i++) {
    if(i != s)
      q.emplace(dist_table[i], i);
  }
  for(auto &p : q) {
    LL d_m = p.first;
    int m = p.second;
    int num_paths = 0;
    for(auto &p2 : connection[m]) {
      LL d_mn = p2.first;
      int n = p2.second;
      LL d_n = dist_table[n];
      // if n is nearer to the start node than m
      // and the shortest path for node m.
      if(0 < count_table[n] && d_m == d_n + d_mn)
        num_paths = (num_paths + count_table[n]) % LIMIT;
    }
    count_table[m] = num_paths;
  }
  return count_table;
}

vector<int> path_count2(const vector<LL>& dist_table) {
  vector<int> count_table(vertex, 0);
  count_table[t] = 1;
  multimap<LL, int> q;
  for(int i = 0; i < dist_table.size(); i++) {
    if(i != t)
      q.emplace(- dist_table[i], i);
  }
  for(auto &p : q) {
    LL d_m = -p.first;
    int m = p.second;
    int num_paths = 0;
    for(auto &p2 : connection[m]) {
      LL d_mn = p2.first;
      int n = p2.second;
      LL d_n = dist_table[n];
      // if n is nearer to the end node than m
      // and the shortest path for node m.
      if(0 < count_table[n] && d_m + d_mn == d_n)
        num_paths = (num_paths + count_table[n]) % LIMIT;
    }
    count_table[m] = num_paths;
  }
  return count_table;
}

int solve() {
  vector<LL> dist_from_s;
  shortest_path_from(s, &dist_from_s);
  const vector<int>& count_from_s = path_count1(dist_from_s);
  const vector<int>& count_from_t = path_count2(dist_from_s);
  LL d_t = dist_from_s[t];
  LL cnt_t = (LL)count_from_s[t];
  LL patterns = (cnt_t * cnt_t) % LIMIT;
  LL patterns_to_remove = 0;

  for(int u = 0; u < vertex; u++) {
    LL d_u = dist_from_s[u];
    // Count up a number of ways to both two meet on the vertex.
    if(2 * d_u == d_t) {
      LL cnt_su = (LL)count_from_s[u];
      LL cnt_tu = (LL)count_from_t[u];
      //patterns_to_remove += (from_s * from_t) % LIMIT;
      patterns_to_remove +=
          (cnt_su * cnt_tu % LIMIT) * (cnt_su * cnt_tu % LIMIT) % LIMIT;
      patterns_to_remove = patterns_to_remove % LIMIT;
    } else if(2 * d_u < d_t) {
      // if u is the node before half distance.
      LL cnt_su = (LL)count_from_s[u];
      for(auto &p : connection[u]) {
        LL d_uv = p.first;
        int v = p.second;
        LL d_v = dist_from_s[v];
        if(d_u + d_uv == d_v && d_t < 2 * d_v) {
          // if v is the node beyond half distance.
          // Count up a number of ways to both two meet on the side.
          LL cnt_tv = (LL)count_from_t[v];
          //patterns_to_remove += (from_u * from_v) % LIMIT;
          patterns_to_remove +=
              (cnt_su * cnt_tv % LIMIT) * (cnt_su * cnt_tv % LIMIT) % LIMIT;
          patterns_to_remove = patterns_to_remove % LIMIT;
        }
      }
    }
  }
  return (patterns - patterns_to_remove + LIMIT) % LIMIT;
}

int main() {
  cin >> vertex >> path;
  cin >> s >> t;
  s--; // 0-origin
  t--;
  connection.resize(vertex);
  int n, m, d;
  for(int i = 0; i < path; i++) {
    cin >> n >> m >> d;
    n--;
    m--;
    connection[n].push_back(make_pair(d, m));
    connection[m].push_back(make_pair(d, n));
  }
  cout << solve() << endl;
}
