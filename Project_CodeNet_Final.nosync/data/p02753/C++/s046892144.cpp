#include <bits/stdc++.h>
using namespace std;
int main(){
  string bus;
  cin >> bus;
  bool A = false;
  bool B = false;
  for (int i = 0; i < 3; i++){
    if (bus.at(i) == 'A') A = true;
    if (bus.at(i) == 'B') B = true;
  }
  if (A && B) cout << "Yes" << endl;
  else cout << "No" << endl;
}
    