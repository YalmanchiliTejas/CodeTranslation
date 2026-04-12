#include<iostream>
using namespace std;

int main () {
  char x;
  cin >> x;
  if ( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
    cout << "vowel\n"; 
  } else {
    cout << "consonant\n";
  }
}