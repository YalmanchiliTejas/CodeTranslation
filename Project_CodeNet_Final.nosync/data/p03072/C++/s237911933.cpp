#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector <int> v(n);
  int v_max = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    cin >> v.at(i);
    if (v.at(i) >= v_max){
      v_max = v.at(i);
      ans += 1;
    }
  }
  cout << ans << endl;
}
 