#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("input.txt","r",stdin);
  string str;
  while(cin>>str) {
    bool a_bool=false;
    bool b_bool=false;
    for(int i=0; i<3; i++) {
      if(str[i]=='A') a_bool=true;
      if(str[i]=='B') b_bool=true;
    }
    if(a_bool && b_bool) cout<<"Yes";
    else cout<<"No";
  }

  return 0;
}
