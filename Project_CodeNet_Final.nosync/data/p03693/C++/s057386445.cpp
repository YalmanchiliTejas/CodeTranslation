#include <bits/stdc++.h>
using namespace std;

int main(void){
  int x, a, b; cin >> x >> a >> b;
  int ans = a * 10 + b;
  if(ans % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
