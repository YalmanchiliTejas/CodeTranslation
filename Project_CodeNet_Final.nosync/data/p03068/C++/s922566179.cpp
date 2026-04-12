#include <iostream>
#include <string>

int main (void){
  int N;
  std::cin >> N;

  std::string S;
  std::cin >> S;

  int K;
  std::cin >> K;

  for(auto i=S.begin(); i!=S.end(); ++i){
    if ( *i != S[K-1] ) std::cout << "*";
    else std::cout << *i ;
  }
  std::cout << std::endl;

  return 0;
}
