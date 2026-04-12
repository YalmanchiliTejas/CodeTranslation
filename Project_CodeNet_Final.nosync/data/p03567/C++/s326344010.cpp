#include <bits/stdc++.h>
using namespace std;

int main() {
  int i;
  string S;
  cin >> S;
  int a;
  a = S.size();
  string ans="No";
  for(i=0;i<a-1;i++) {
    if(S[i]=='A'&&S[i+1]=='C') ans="Yes";
  }
  cout << ans << endl;
  return 0;  
}