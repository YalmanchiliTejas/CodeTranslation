#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

bool can_go_all(vector<vector<int>> &map,vector<int> &path,int x){
  if(x == path.size()) return true;
  
  bool ret = false;
  if(x == 0){
    for(auto i:map.at(0)){
       if(path.at(x) == i) ret = can_go_all(map,path,x+1);
    }
    return ret;
  }
  for(auto i:map.at(path.at(x-1))){
    if(path.at(x) == i){
      ret = can_go_all(map,path,x+1);
    }
  }
  
  return ret;
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> map(N);
  rep(i,M){
    int dct1,dct2;
    cin >> dct1 >> dct2;
    map.at(dct1-1).push_back(dct2-1);
    map.at(dct2-1).push_back(dct1-1);
  }
  
  vector<int> order;
  vector<vector<int>> orderindex;
  rep(i,N-1){
    order.push_back(i+1);
  }
  sort(all(order));
  do {
    orderindex.push_back(order);
  } while (next_permutation(all(order)));
  
  int cnt = 0;
  int x = 0;
  for(auto i:orderindex){
    if(can_go_all(map,i,x)) cnt++;
  }
  
  cout << cnt << endl;
}