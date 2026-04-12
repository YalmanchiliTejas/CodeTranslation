#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, X, M;
  cin >> N >> X >> M;
  
  vector<int64_t> vec(1,X);
  set<int64_t> S;
  S.insert(X);
  
  while(true){
    X *= X;
    X %= M;
    if(S.count(X)){
      break;
    }
    else{
      vec.push_back(X);
      S.insert(X);
    }
  }
  
  int loop = -1;
  for(int i=0; i<vec.size(); i++){
    if(X == vec[i]){
      loop = i;
    }
  }
  
  int64_t len_loop = vec.size() - loop;
  
  int64_t ans = 0;
  for(int i=0; i<loop; i++){
    if(N == 0){
      break;
    }
    ans += vec[i];
    N--;
  }
  
  int64_t L = 0;
  for(int i=loop; i<vec.size(); i++){
    L += vec[i];
  }
  
  ans += L*(N / len_loop);
  N %= len_loop;
  
  for(int i=loop; i<vec.size(); i++){
    if(N == 0){
      break;
    }
    ans += vec[i];
    N--;
  }
    
  cout << ans << endl;  
  
}