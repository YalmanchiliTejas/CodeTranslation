#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}