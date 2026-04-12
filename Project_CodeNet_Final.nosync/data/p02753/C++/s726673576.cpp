#include <bits/stdc++.h>

using namespace std;

int main(){
  char s[3];
  cin >> s;
  sort(s,s+3);
  bool can = (s[0] != s[1]) || (s[1] != s[2]);
  (can)? cout << "Yes": cout << "No";
  return 0;
}