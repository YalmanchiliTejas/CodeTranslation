#include<iostream>
#include<string>
using namespace std;

int main(){

  int i;
  char c;
  string s="aiueo";

  cin>>c;

  for( i=0;i<5;i++) if(s[i]==c) break;

  if(i==5) cout<<"consonant"<<endl;
  else cout<<"vowel"<<endl;
  
  return 0;
}
