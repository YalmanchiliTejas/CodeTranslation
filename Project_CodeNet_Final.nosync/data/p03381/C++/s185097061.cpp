#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  vector<int> t(a);
for (int i = 0; i < a; i++) {
  cin >> t.at(i);
}
  vector<int> v(a);
  for (int i = 0; i < a; i++) {
  v.at(i) = t.at(i);
}
  sort(t.begin(), t.end());
  int r;
  r = a / 2;
  int k;
  int l;
  k = t.at(r-1);
  l = t.at(r);
  for(int i = 0; i < a; i++){
    if(v.at(i) <= k){
      cout << l << endl;}
    else{cout << k << endl;}
  }
  }