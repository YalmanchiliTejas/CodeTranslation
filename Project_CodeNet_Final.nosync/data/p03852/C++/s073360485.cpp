#include <iostream>
using namespace std;
int main(){
  char a;
  cin>>a;
  if('a'==a||'i'==a||'u'==a||'e'==a||'o'==a){
    cout<<"vowel";
  }else{
    cout<<"consonant";
  }
  return 0;
}