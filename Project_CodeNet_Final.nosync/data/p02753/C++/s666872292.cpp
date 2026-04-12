#include <iostream>
using namespace std;
int main() {
  string str;
  cin >> str;
  for(int i = 0; i < str.size()-1; i++) {
    if(str.at(i) != str.at(i+1)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}