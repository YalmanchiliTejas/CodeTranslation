#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  string S,ans = "Yes";
  cin >> S;
  
  if(S=="AAA" || S=="BBB") ans="No";
  cout << ans << endl;
  
  return 0;
}
