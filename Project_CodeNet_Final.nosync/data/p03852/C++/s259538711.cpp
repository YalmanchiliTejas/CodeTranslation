#include<iostream>
using namespace std;

int main(){
  char s;
  cin >> s;
  if (s == 'a' || s == 'u' || s == 'i' || s == 'e' || s == 'o'){
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}