#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  double r1, r2; cin >> r1 >> r2;
  
  cout << setprecision(20) << r1 * r2 / (r1 + r2) << '\n';
  
  return 0;
}