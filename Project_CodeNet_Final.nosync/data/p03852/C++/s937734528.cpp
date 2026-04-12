#include <iostream>
using namespace std;

int main(void){
  char c;
  bool flag = false;

  cin >> c;

  switch(c){
    case 'a' :
    case 'e' :
    case 'i' :
    case 'o' :
    case 'u' : flag = true;
             break;
    default : break;
  }

  if (flag) cout << "vowel" << endl;
  else cout << "consonant" << endl;

  return 0;
}