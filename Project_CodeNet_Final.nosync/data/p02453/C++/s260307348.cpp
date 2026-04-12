#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int k;
    cin >> k;
    int tv = n;
    int fv = -1;
    while (tv - fv > 1){
      int mv = (tv + fv) / 2;
      if (a[mv] >= k){
        tv = mv;
      } else {
        fv = mv;
      }
    }
    cout << tv << endl;
  }
}
