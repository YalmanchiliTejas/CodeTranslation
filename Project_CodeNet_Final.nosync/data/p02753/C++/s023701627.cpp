#include <iostream>
#include<string>
using namespace std;
main() {
  string s;
  cin>>s;
  if (s[0]!=s[1] || s[0]!=s[2]) {
    cout << "Yes";
  }
  else
  cout <<"No";
}
