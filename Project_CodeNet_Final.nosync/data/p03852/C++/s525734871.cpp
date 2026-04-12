#include<iostream>
#include<string.h>
using namespace std;
string s;
int main()
{ 
  cin >> s;
  if(s=="a" || s=="e" || s=="i" || s=="o" || s=="u")printf("vowel");
  else printf("consonant");
}