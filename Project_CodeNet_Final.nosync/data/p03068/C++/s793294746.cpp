#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  int N, K;
  cin >> N >> S >> K;
  
  char target_character = S.at(K-1);
  
  int i;
  for (i=0; i<S.size(); i++){
    if(S.at(i) == target_character){
      cout << S.at(i);
    }else{
      cout << "*";
    }
  }
  cout << endl;
}