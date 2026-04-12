#include <iostream>

using namespace std;

int main(){
  char x; cin >>x;
  switch(x){
    case 'a': cout << "vowel\n";
    break;
    case 'e': cout << "vowel\n";
    break;
    case 'i': cout << "vowel\n";
    break;
    case 'o': cout << "vowel\n";
    break;
    case 'u': cout << "vowel\n";
    break;
    default: cout << "consonant\n";
  }
}