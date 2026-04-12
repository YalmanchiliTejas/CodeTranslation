#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
  string s;
  cin >> s;
  bool a = false;
  bool b = false;
  rep(i,3){
    if(s.at(i) == 'A') a = true;
    if(s.at(i) == 'B') b = true;
  }
  string ans = "No";
  if(a && b) ans = "Yes";
  cout << ans << endl;
return 0;
}