#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  bool jud = false;
  
  cin >> str;
  
  for(int i = 0 ; i < str.length() ; i++){
    if(str[i] == 'A'){
      if(i + 1 == str.length()) break;
      else if(str[i+1] == 'C'){
        jud = true;
        break;
      }
    }
  }
  
  if(jud) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}