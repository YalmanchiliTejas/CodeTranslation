#include <iostream>
#include <string>
using namespace std;
int main() {
  int a_co=0;
  string s;
  cin >> s;
  for(int i=0; i<3; i++) {
    if (s[i] == 'A') a_co++;
  }
  if (a_co==3 || a_co==0) {
    cout << "No" << endl;
  } else { 
    cout << "Yes" << endl;
  }
}