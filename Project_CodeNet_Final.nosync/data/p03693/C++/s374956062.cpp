#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;cin >>a>>b>>c;
  string ans="NO";
  if((b*10+c)% 4==0)ans="YES";
  cout << ans<<endl;
}