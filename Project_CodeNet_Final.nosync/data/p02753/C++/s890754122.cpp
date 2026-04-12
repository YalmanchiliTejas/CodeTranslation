#include<iostream>

using namespace std;

int main(void)
{
  char s[4];
  
  cin>>s;
  
  if(((s[0]=='A')&&(s[1]=='A'))&&(s[2]=='A')){
    puts("No"); return 0;
  }
  
  if(((s[0]=='B')&&(s[1]=='B'))&&(s[2]=='B')){
    puts("No"); return 0;
  }
  
  puts("Yes");
  
  return 0;
}