#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  char c;
  std::cin >> c;
  switch (c) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      std::cout << "vowel" << std::endl;
      break;
    default:
      std::cout << "consonant" << std::endl;
  }

  return EXIT_SUCCESS;
}
