#include<iostream>
#include<string>
using namespace std;

int main(){
  
  string c;
  cin >> c;
  
  string s[5] = {"a","e","u","i","o"};
 
  if(c == s[0]) cout <<"vowel\n";
  else if(c == s[1]) cout <<"vowel\n";
  else if(c == s[2]) cout <<"vowel\n";
  else if(c == s[3]) cout <<"vowel\n";
  else if(c == s[4]) cout <<"vowel\n";
  else cout <<"consonant\n";
  
}