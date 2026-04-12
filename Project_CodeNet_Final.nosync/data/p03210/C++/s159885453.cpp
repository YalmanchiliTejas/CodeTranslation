#include<bits/stdc++.h>
using namespace std;

int main(void){
  int X;
  bool ans = false;
  cin >> X;
  if(X == 7 || X == 5 || X == 3)
    ans = true;
  if(ans) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
