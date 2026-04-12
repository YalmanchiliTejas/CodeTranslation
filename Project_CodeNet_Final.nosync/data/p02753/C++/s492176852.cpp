#include <bits/stdc++.h>
using namespace std;

int main(void){
  string s;
  cin>>s;
  int c1=0,c2=0;
  for (int i = 0; i < (int) s.size(); i++) {
    if(s[i]=='A') c1++;
    else if(s[i]=='B') c2++;
  }
  if(c2 && c1) cout<<"Yes\n";
  else cout<<"No\n";
}