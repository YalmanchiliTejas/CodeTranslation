#include <iostream>
using namespace std;
int main(){
  char s; cin >>s;
  if(s == 'a' or s == 'i' or s == 'u' or s == 'e' or s == 'o')
    cout << "vowel" << endl;
  else
    cout << "consonant" <<endl;
}