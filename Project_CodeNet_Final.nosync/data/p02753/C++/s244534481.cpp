#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  string S;
  cin >> S;
  if (S.compare("BBB") == 0 || S.compare("AAA") == 0) {
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}
