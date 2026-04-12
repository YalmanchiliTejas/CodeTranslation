#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool a=s.find("AB")==string::npos;
  bool b=s.find("BA")==string::npos;
  if(a&&b) puts("No");
  else puts("Yes");
}