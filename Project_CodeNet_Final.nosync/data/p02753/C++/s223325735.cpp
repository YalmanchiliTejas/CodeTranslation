#include <iostream>
using namespace std;

// driver code
int main() {
  string s;
  cin>>s;
  size_t found_A = s.find("A");
  size_t found_B = s.find("B");
  if (found_A != string::npos && found_B != string::npos)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
