#include <bits/stdc++.h>
using namespace std;

int main() {

   string S ;
  string ans = "Yes";
  cin >> S;
  if(S[0]==S[1] && S[1] == S[2] && S[2]==S[0])
      ans="No";
  
  cout << ans << endl;
}
