#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> graph(n+1,vector<bool>(n+1));
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  vector<int> order(n);
  for(int i=0;i<n;i++) order[i] = i+1;

  ll cnt = 0;

  do{
    if(order[0] != 1) continue;

    for(int i=0;i<n-1;i++){
      if(!graph[order[i]][order[i+1]] && !graph[order[i+1]][order[i]]){
        break;
      }
      if(i == n-2){
        cnt++;
      }
    }
  }while(next_permutation(order.begin(),order.end()));

  cout << cnt << endl;
}
