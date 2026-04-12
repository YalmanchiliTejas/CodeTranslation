#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  if(count(&s[0],&s[2]+1,'A')==0 || count(&s[0],&s[2]+1,'B')==0)cout << "No";
  else cout << "Yes";

  return 0;
}