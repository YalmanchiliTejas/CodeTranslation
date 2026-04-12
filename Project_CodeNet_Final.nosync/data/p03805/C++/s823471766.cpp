#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> vec, int n, int max_n, bitset<9> ck, int r = 0) {
  if(ck.count() == max_n ) return ++r;
  
  for(int x: vec.at(n)) {

    if(!ck.test(x)) {
      ck.set(x);
      r = dfs( vec, x, max_n, ck, r);
      if( x != n ) ck.reset(x);
    }
  }
  return r;

};
 
int main() {
  int N,M;
  cin >> N >> M;
  
  vector<vector<int>> A(N+1);
  
  for (int i=1; i<=M; i++) {
    int a1,a2;
    cin >> a1 >> a2;
    A.at(a1).push_back(a2);
    A.at(a2).push_back(a1);
  }
  
  bitset<9> b;
  b.set(1);
  int res =  dfs( A, 1, N, b);
  
  cout << res << endl;
  
}