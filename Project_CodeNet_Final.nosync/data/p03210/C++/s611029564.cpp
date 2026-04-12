#include <iostream>

int main(){
  int age_of_takahashi;
  std::cin >> age_of_takahashi;
  std::cout << ((age_of_takahashi > 2 && age_of_takahashi < 8 && (age_of_takahashi % 2 != 0)) ? "YES" : "NO");  
  return 0; 
}