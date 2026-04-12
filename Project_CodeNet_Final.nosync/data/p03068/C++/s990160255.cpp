#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string str;
  cin >> N >> str >> K;
  
  for(int i = 0; i < N; i++){
    if(str.at(i) != str.at(K - 1)){
      str.at(i) = '*';
    }
  }
  
  cout << str << endl;
}
      
      
  
  