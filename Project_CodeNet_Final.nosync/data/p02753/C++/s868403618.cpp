#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(equal(s.begin(), s.end(), "AAA") || equal(s.begin(), s.end(), "BBB")) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}