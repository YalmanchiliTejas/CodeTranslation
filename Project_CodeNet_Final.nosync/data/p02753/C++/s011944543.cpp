#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >>s;
  bool a = false;
  bool b = false;

  if(s[0] == 'A') a = true;
  if(s[0] == 'B') b = true;
  if(s[1] == 'A') a = true;
  if(s[1] == 'B') b = true;
  if(s[2] == 'A') a = true;
  if(s[2] == 'B') b = true;

  if(a && b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}