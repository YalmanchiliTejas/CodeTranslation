#include <iostream>

int main()
{
  int age;
  std::cin >> age;
  std::cout << ((age==3 || age==5 || age==7) ? "YES" : "NO");
}
