#include<iostream>
#include<string>
using namespace std;
int main(void){
  string a;
  cin >> a;
  if(a == "a" || a == "e" || a == "i" || a == "o" || a == "u")
  cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;
  return 0;
}