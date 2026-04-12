#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  vector<int> H(N);
  for(int i=0; i<N; i++){ cin >> H.at(i); }
  
  int res;
  for(int i=0; i<N; i++){
    for(int j=0; j<i+1; j++){
      if( H.at(i)<H.at(j) ){ break; }
      if(j==i){ res++; }
    }
  }
  
  cout << res << endl;
}