#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define AS(a) (sizeof(a)/sizeof(a[0]))
using namespace std;

struct V {
  int id;
  vector <V> next;
};

vector<V> list;

int dfs(int id,bool *vi, int N) {
  bool k = true;
  for(int i = 0; i < N; i++) {
    if(!vi[i]) {
      k = false;
      break;
    }
  }

  if(k) return 1;
  int sum = 0;
  for(V vv : list.at(id).next) {
    if(vi[vv.id]) continue;
    vi[vv.id] = true;
    sum += dfs(vv.id,vi,N);
    vi[vv.id] = false;
  }
  return sum;


}

int main() {
  int N,M;
  cin >> N >> M;
  int a[M],b[M];
  for(int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
  }

  for(int i = 0; i < N; i++) {
    list.push_back(V());
    list[i].id = i;
    list[i].next.clear();
  }

  for(int i = 0; i < M; i++) {
    list[a[i]-1].next.push_back(list[b[i]-1]);
    list[b[i]-1].next.push_back(list[a[i]-1]);
  }
  bool vis[N];
  for(int i = 0; i < N; i++) {
    vis[i] = false;
  }
  vis[0] = true;
  cout << dfs(0,vis,N) << endl;


}
