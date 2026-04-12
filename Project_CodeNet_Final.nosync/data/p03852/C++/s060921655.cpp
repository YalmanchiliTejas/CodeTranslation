#include <iostream>
#include <string>
using namespace std;
int main() {
  char c;
  char v[]={"aeiou"};
  cin>>c;
  bool s=true;
  for (int i=0;i<sizeof(v);i++){
    if (c==v[i]){
      cout<<"vowel";
      s=false;
      break;
    }
    }
    if(s){
      cout<<"consonant";
    }  
return 0;
}