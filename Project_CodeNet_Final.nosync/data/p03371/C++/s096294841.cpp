#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
  int A,B,C; cin >> A >> B >> C;
  int X,Y; cin >> X >> Y;
  map<int,int> m;
  m.insert(make_pair(X,A));
  m.insert(make_pair(Y,B));
  
  cout << min(X,Y)*min(A+B,2*C) + (max(X,Y)-min(X,Y))*(min(m.at(max(X,Y)),2*C));
  
  return 0;
}