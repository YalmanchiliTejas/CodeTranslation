#include <iostream>
#include <string>

using namespace std;

int main(){
  string data="aiueo";
  char d;
  cin>>d;
  
  if(data.find(d)!=string::npos){
    cout<<"vowel";
    
  }
  else{
    cout<<"consonant";
  }
}