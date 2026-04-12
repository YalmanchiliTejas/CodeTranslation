#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string c;
  cin >> c;
  string aiueo = "aiueo";
  if (aiueo.find(c[0]) != string::npos) cout << "vowel";
  else cout << "consonant" << endl;
  return 0;
}
