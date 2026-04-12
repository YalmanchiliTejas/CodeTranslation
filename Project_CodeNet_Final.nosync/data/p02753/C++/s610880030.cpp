#include <bits/stdc++.h>
using namespace std ;

int main(){
  string s;
  bool a=false, b=false;
  cin >> s;
  for(int i=0;i<3;i++){
    if(s[i]=='A')a=true;
    if(s[i]=='B')b=true;
  }
  if(a==true&&b==true)puts("Yes");
  else puts("No");
  return 0;
}
