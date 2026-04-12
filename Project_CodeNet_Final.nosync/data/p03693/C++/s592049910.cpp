#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string s(3,'0');
  rep(i,3){
    cin >> s.at(i);
  }
  int x = stoi(s);
  if(x%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  
}