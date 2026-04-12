#include<iostream>

using namespace std;

int main(void)
{
  string s; cin>>s;
  
  if((s[0]==s[1])&&(s[1]==s[2])){puts("No");}
  else{puts("Yes");}
  
  return 0;
}