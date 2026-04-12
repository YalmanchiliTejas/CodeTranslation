#include <bits/stdc++.h>
using namespace std;

int OSP(vector<vector<int> > graph, vector<int> c, int now, int n, int count, int x){
  if(count == 0) return 1;

  int sum = 0;
  bool flag = false;
  for(int i = 0; i < graph[now].size(); i++){
    if(c[graph[now][i]] == 0){
      flag = true;
      c[graph[now][i]] = 1;
      sum += OSP(graph, c, graph[now][i], n, count-1, x*10+graph[now][i]);
      c[graph[now][i]] = 0;
    }
  }
  if(flag == false) return 0;
  return sum;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m),b(m),c(n, 0);
  c[0] = 1;
  vector<vector<int> > graph(n);
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i]; a[i]--; b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }



  cout << OSP(graph, c, 0, n, n-1, 0) << endl;

}
