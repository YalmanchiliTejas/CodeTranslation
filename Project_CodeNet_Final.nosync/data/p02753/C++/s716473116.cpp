#include <iostream>

using namespace std;

int main(){
  string str;
  cin >> str;
  bool contain_AB = str.find("AB") != std::string::npos;
  bool contain_BA = str.find("BA") != std::string::npos;
  if(contain_AB || contain_BA) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}