#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> nodes, vector<vector<int>> edges){
  bool ans = true;
  
  for(int i = 0; i < nodes.size()-1; i++){
    auto v = edges.at(nodes[i]); 
    auto itr = find(v.begin(), v.end(), nodes[i+1]);
    if(itr == v.end()){
      ans = false;
      break;
    }
  }
  return ans;
}

int main(){
  int N, M;
  cin >> N >> M;
  long ans = 0;
  
  vector<vector<int>> v(N);
  for(int i = 0; i < M; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    v.at(tmp1-1).push_back(tmp2-1);
    v.at(tmp2-1).push_back(tmp1-1);
  }
  
  vector<int> nodes;
  nodes.push_back(0);
  for(int i = 1; i < N; i++){
    nodes.push_back(i);
  }
  
  cerr << v.size() << " " << nodes.size() << endl;
   
  do {
    if(check(nodes, v)){
      ans += 1;
    }
  } while (next_permutation(nodes.begin()+1, nodes.end()));
  
  cout << ans << endl;
}