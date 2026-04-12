#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n); for(int & i : a) cin >> i;
  int mx = 0, q = 0;
  for(int i = 0; i < n; i++){
    mx = max(mx, a[i]);
    q += a[i] >= mx;
  }
  cout << q << endl;
  return 0;
}
  