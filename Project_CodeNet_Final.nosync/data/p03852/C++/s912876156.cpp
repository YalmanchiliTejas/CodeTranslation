#include<iostream>
 
int main()
{
  char c;
  std::cin >> c;
  switch(c)
  {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      std::cout << "vowel";
    break;
    default:
      std::cout << "consonant";
  }
}