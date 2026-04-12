#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  char a = s[0];
  if( a != s[1] || a !=s[2])
    cout << "Yes";
  else
    cout << "No";
  return 0;
}