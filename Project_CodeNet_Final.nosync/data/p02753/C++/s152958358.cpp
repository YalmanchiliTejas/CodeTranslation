#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  
  cin >> str;

  
  if (str.find("AB") != std::string::npos || str.find("BA") != std::string::npos ) {
   puts("Yes");
}
  else{
    cout << "No" <<endl;
  }
  
  
}
