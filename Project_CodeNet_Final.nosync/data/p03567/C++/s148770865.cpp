#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >>s;
  bool AC = false;
  rep(i,s.size()-1){
    string s1;
    for(int j = i; j<i+2; j++){
      s1 += s[j];
    }
    if(s1=="AC") AC = true;
  }
  if(AC) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}