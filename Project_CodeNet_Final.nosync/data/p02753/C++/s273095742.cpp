#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  bool ok=false;
  char tmp = s[0];
  for(char c: s){
    if(tmp==c)  continue;
    else{
      ok = true;
      break;
    }
  }

  if(ok)  cout<<"Yes"<<endl;
  else  cout<<"No"<<endl;

  return 0;
}
