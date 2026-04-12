#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  if (s != "AAA" && s != "BBB")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
