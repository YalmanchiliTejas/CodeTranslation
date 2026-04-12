#include <bits/stdc++.h>
using namespace std;

int main() {
  string V = "aiueo";
  char c;
  int ans = 0;
  cin >> c;
  for(int i = 0; i < 5; i++){
    if(c == V.at(i)) ans++;
  }
  if(ans) cout << "vowel";
  else cout << "consonant";
}
