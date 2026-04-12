#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  char c;
  std::cin >> c;

  if(c == 'a'||c=='e'||c=='u'||c=='i'||c=='o'){
    std::cout << "vowel" << '\n';
  }
  else{
    std::cout << "consonant" << '\n';
  }
  return 0;
}
