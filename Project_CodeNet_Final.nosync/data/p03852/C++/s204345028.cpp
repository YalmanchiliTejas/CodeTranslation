#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
void solve(){
  char c; cin >> c;
  if(c == 'a' || c == 'i' || c == 'e' || c == 'u' || c == 'o') cout << "vowel\n";
  else cout << "consonant\n";
  return;
}

int main(){
  solve();
  return 0;
}
