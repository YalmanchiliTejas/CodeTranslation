#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q;
  cin >> n;
  vector<int> a(n + 1);
  a[n] = 1e9 + 1;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> q;
  int k[q];
  for(int i = 0; i < q; i++){
    cin >> k[i];
  }
  for(int i : k){
    cout << lower_bound(a.begin(), a.end(), i) - a.begin() << endl;
  }
  return 0;
}
