#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  string S;
  cin >> S;
  
  int K;
  cin >> K;
  
  char x = S.at(K - 1);
  
  for(char &c : S){
    if(c != x)
      c = '*';
  }
  
  cout << S << endl;
}
