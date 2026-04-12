#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  bool can = false;
  if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) can = true;
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}