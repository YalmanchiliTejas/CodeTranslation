#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  cout << ((s.find("A") != std::string::npos && s.find("B") != std::string::npos) ? "Yes" : "No");
}