#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, M;
  cin >> N >> M;
  
  bool ans = false;
  if(N == M){
    ans = true;
  }
  
  if(ans){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}