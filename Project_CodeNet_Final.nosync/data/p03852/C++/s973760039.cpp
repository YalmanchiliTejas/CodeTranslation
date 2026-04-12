#include<iostream>
using namespace std;
int main(void){
  
  char c;

  cin >> c;

  if((char)c == 'a' || (char)c == 'i'  || (char)c == 'u' || (char)c == 'e' || (char)c == 'o' ){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }

  return 0;
}