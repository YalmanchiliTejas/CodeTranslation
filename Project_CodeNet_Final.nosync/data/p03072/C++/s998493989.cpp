#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> Hs(N);
  for (int i = 0; i < N; i++){
    cin >> Hs.at(i);
  }
  
  int Ans = 1;
  bool judge = 1;
  for (int i = 1; i < N; i++){
    for (int j = 0; j < i; j++){
      if ( Hs.at(i) < Hs.at(j) ){
        judge = 0;
      }     
    }
    if (judge){
      Ans += 1;
    }
    else{
      judge = 1;
    }
  }
  cout << Ans << endl;
  
}