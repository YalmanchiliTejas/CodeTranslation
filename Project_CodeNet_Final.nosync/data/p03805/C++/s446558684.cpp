#include <bits/stdc++.h>
using namespace std;

bool path_aruka(vector<int> path, vector<pair<int, int>> edges){
  vector<int> path_ret(path.size());
  copy(path.begin(), path.end(), path_ret.begin());
  path_ret.insert(path_ret.begin(), 1);
  /*
  for(int i = 0; i < path_ret.size(); i++)
      cout << path_ret.at(i);
  */

  for(int i = 0; i < path_ret.size() - 1; i++){
    for(int j = 0; j < edges.size(); j++){
      if((path_ret.at(i) == edges.at(j).first && path_ret.at(i+1) == edges.at(j).second)||
         (path_ret.at(i) == edges.at(j).second && path_ret.at(i+1) == edges.at(j).first))
        if(i == path_ret.size() - 2)
         return true;
      	else
          break;
      if(j == edges.size() - 1)
        return false;
    }
  }
}



int main(){
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++){
    cin >> edges.at(i).first >> edges.at(i).second;
  }

  //2~nの頂点リストを生成
  vector<int> vertexes(n-1);
  iota(vertexes.begin(), vertexes.end(), 2);

  //(始点を除く)頂点の全組み合わせをループ
  
  int cnt = 0;
  do{
    if(path_aruka(vertexes, edges))
      cnt++;
    //cout << endl;
  }while(next_permutation(vertexes.begin(), vertexes.end()));

  cout << cnt << endl; 
  
}