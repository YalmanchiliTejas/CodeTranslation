
#include<iostream>
using namespace std;
int main() {
  char c;
  cin>>c;
  string j = "aiueo";
  for(int i = 0;i < 5;i++){
    if( c == j.at(i)){
      cout<<"vowel"<<endl;
      return 0;
    }
  }
  cout<<"consonant"<<endl;
  }