//特殊な状態の列挙
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

vector<vector<bool>> routes;
vector<bool> node_used;
vector<int> route;
int n, m, count=0;

void perm(int pos){
  if(pos == n){
    for(int i=1; i<n; i++){
      if(!routes.at(route[i-1]).at(route[i])) return;
    }
    count++;
    return;
  }

  for(int i=1; i<n; i++){
    if(!node_used[i]){
      route[pos] = i;
      node_used[i] = true;
      perm(pos+1);
      node_used[i] = false;
    }
  }

  return;
}

int main(){
  //input
  int tmp_1, tmp_2;
  cin >> n >> m;

  vector<vector<bool>> routes_buf(n, vector<bool>(n, false));
  routes.swap(routes_buf);

  vector<bool> node_used_buf(m, false);
  node_used_buf.at(0) = true;
  node_used.swap(node_used_buf);

  vector<int> route_buf(n);
  route.swap(route_buf);

  for(int i=0; i<m; i++){
    cin >> tmp_1 >> tmp_2;
    routes.at(tmp_1-1).at(tmp_2-1) = true;
    routes.at(tmp_2-1).at(tmp_1-1) = true;
  }

  perm(1);

  cout << count << endl;
  return 0;
}