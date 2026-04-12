#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  std::cin >> s;
  for (int i = 0; i < s.length() - 1; i++) {
    if(s[i] == 'A' and s[i + 1] == 'C'){
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}
