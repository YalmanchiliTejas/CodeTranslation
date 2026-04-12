#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
using namespace std;
int main(void){
  string s;
  cin >> s;
  
  int n = s.length();
  
  bool AC = false;
  
  for(int i=0;i<n - 1;i++){
    if(s[i] == 'A' && s[i + 1] == 'C')
      AC = true;
  }
  
  if(AC)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}
