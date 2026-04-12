#include <iostream>

using namespace std;

int main(void){
  char x;
  cin >> x;
  if(x== 'a' || x== 'i' || x== 'u' || x== 'e' || x== 'o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}