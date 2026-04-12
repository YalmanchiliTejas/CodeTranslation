#include <iostream>
using namespace std;

int main(void){
  int i;
  char s[3];
  
  for(i = 0; i < 3; i++)
    cin >> s[i];
  
  if(s[0] != s[1] || s[1] != s[2] )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}