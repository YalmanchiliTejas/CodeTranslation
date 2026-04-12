#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int k; cin >> k; k--;
  char c = s.at(k);
  for (int i = 0; i < n; i++){
    if (s.at(i) != c) s.at(i) = '*';
  }
  cout << s << endl;
  return 0;
}