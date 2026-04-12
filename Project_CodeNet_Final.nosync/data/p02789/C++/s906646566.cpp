#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, M;
  bool success = false;
  cin >> N >> M;
  if(N == M)
    success = true;
  if(success) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
