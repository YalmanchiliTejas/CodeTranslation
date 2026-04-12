#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;
  string ans="Yes";
  if(S[0]==S[1]&&S[1]==S[2])ans="No";
  cout<<ans<<endl;
}