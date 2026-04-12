#include <bits/stdc++.h>
using namespace std;

int main(){
  string sta;
  cin >> sta;
  bool a=0;
  bool b=0;
  for (char c:sta){
    if(c=='A') a=1;
    if(c=='B') b=1;
    if(a&&b) break;
  }
  cout << (a and b ? "Yes":"No") << endl;
}