#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  string s;
  cin >> s;
  bool ok = false;
  for (int i = 0; i < 2; i++) {
    if (s[i] != s[i+1]) ok = true;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
} 