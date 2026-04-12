#include<iostream>
#include<string>
using namespace std;
int main(void){
  string s;
  cin>>s;
  if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;
  return 0;
}