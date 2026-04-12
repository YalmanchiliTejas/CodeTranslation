#include <iostream>
using namespace std;

int main(void){
  char s[5];
  
  cin >> s;
  cout << (s[0]==s[1]&&s[1]==s[2]?"No":"Yes") << endl;
  return 0;
}
