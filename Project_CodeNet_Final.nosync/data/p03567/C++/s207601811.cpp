#include <iostream>

using namespace std;

int main(void){
  string aaa;

  cin >> aaa;

if (aaa.find("AC") != std::string::npos) {
   cout << "Yes";
}
else{
  cout << "No";
}
}