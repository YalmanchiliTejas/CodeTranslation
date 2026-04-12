#include <iostream>
#include <string>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  if(s.substr(0, 1) == "A" && s.substr(1, 1) == "A" && s.substr(2, 1) == "A"){
    cout << "No" << endl;
    return 0;
  }
  if(s.substr(0, 1) == "B" && s.substr(1, 1) == "B" && s.substr(2, 1) == "B"){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}