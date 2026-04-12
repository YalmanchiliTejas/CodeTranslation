#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = N * 800;
  ans -= (N/15) * 200;
  cout << ans << endl;
  return 0;
}