#include <iostream>
#include <string>
using namespace std;

int main(){
  string c;
  cin >> c;
  char s = c[0];
  if(s =='a' ||s == 'e' ||s == 'i' || s=='o' || s== 'u' ){
    cout << "vowel\n";
  }else cout << "consonant\n";
  return 0;
}
