#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  
  int a = 0, b = 0;
  for(int i = 0; i < 3; i++){
    if(s[i] == 'A') a++;
    else b++;
  }
  
  if(a && b) puts("Yes");
  else puts("No");
  
  return 0;
}