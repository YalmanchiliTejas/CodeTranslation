#include <bits/stdc++.h>
using namespace std;

int main() {
  string c,ans="vowel";
  cin >> c;
  for (int i=0;i<c.size();i++) {
    if (c.at(i)!='a' and c.at(i)!='i' and c.at(i)!='u' and c.at(i)!='e' and c.at(i)!='o'){
      ans="consonant";
    }
  }
  cout << ans << endl;
}