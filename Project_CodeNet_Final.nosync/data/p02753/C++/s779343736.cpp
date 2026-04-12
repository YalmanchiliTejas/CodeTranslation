#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string str;
  cin >> str;
  cout << ((str.find("A")==string::npos || str.find("B")==string::npos) 
            ? "No" : "Yes") << endl;
  return 0;
}