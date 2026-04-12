#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s;
  cin >> s;
  int l = s.length();
  bool f = false;
  rep(i,l-1) {
    if(s[i] == 'A' and s[i+1] == 'C') f = true;
  }
  cout << (f ? "Yes" : "No") << endl;
  return 0;
}