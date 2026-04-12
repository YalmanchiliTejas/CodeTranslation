#include <iostream>

int main() {
  char S[3];

  for (int i=0; i<3; i++) std::cin >> S[i];

  bool isExist = false;
  if (S[0] != S[1]) isExist = true;
  if (S[0] != S[2]) isExist = true;
  if (S[1] != S[2]) isExist = true;


  if (isExist) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}

