#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i <(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main(){
  string s;
  cin >> s;
  string ans = "Yes";
  if( s[0] == s[1] && s[1]== s[2]) ans = "No";
  cout << ans << endl;
  return 0;
}