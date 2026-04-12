#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const long long MOD = 1000000007;

int main(){
  string s;
  bool ans = false;
  cin >> s;
  rep(i,2){
    if(s.at(i) != s.at(i+1)) ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
