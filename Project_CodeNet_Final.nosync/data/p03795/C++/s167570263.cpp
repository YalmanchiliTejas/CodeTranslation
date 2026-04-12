#include "bits/stdc++.h"
using namespace std;
int main(void){
  int ans,A,B,C;
  cin >> A;
  B = A * 800;
  C = B/12000*200;
  ans = B - C;
  cout << ans << endl;
}