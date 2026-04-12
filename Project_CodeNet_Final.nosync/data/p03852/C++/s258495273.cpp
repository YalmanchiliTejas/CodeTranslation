#include<iostream>
#include <regex>
using namespace std;
int main(){
  string c;
  cin>>c;
  regex re("[aouie]");
  if(regex_match( c, re )){
    cout << "vowel" << endl;
  }
    else{
      cout << "consonant" << endl;
    }
    return 0;
  }