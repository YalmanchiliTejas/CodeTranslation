#include <iostream>
using namespace std;

int main(){
  char c;
  cin >> c;

  if(c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }

  return 0;
}
