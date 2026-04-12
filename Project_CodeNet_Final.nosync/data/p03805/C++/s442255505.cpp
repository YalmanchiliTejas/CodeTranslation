#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
void out_vector(vector<int> v) {
  REP(i,v.size()) { cout << v[i] << '\n'; }
}

int cnt_node(int p[][2], bool visited[], int n, int m, int now){
  bool v[n];
  vector<int> next;
  // out_vector(next);
  copy(visited, visited+n, v);
  v[now] = true;
  REP(i,m){
    if (p[i][0] == now) { if (!v[p[i][1]]) { next.push_back(p[i][1]); } }
    if (p[i][1] == now) { if (!v[p[i][0]]) { next.push_back(p[i][0]); } }
  }
  if (next.size() == 0) {
    REP(i,n) {
      if (!v[i]) return 0;
    }
    return 1;
  }
  int sum = 0;
  REP(i, next.size()) {
    sum += cnt_node(p,v,n,m,next[i]);
  }
  return sum;
}


int main(void) {
  int N, M;
  cin >> N >> M;
  int P[M][2];
  REP(i,M) { cin >> P[i][0] >> P[i][1]; }
  REP(i,M){ P[i][0]--; P[i][1]--; }
  bool visited[N] = {};
  cout << cnt_node(P,visited,N,M,0) << '\n';;
}
