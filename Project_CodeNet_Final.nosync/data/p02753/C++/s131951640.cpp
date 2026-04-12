#include <iostream>
#include <string>
 
using namespace std;
 
int main(void){
  string str;
  cin >> str;
  if(str == "AAA" || str == "BBB"){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
 }
