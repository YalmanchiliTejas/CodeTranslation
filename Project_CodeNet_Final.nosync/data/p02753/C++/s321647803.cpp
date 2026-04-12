#include <iostream>

using namespace std;

int main(){
  string text;
  cin >> text;
  if (text == "AAA" || text == "BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}