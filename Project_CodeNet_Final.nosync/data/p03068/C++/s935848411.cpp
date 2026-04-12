#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  string S;
  char X = '*',t;
  cin >> N>>S>>K;  
  K--;
  char Y = S.at(K);

  
  
  for(int i=0;i<N;i++){
    t = S.at(i);
    if(t != Y){
     S.at(i) = X; 
    }
  }
  
  cout << S <<endl;
}