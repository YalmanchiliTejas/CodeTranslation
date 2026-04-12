#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
  const std::string left =  "qwertasdfgzxcvb";
  const std::string right = "yuiophjklnm";

  while (true) {
    std::string s;
    std::cin >> s;
    if (s == "#")
      break;
    int side = -1;
    int sw = 0;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
      if (left.find(*it) != std::string::npos) {
        if (side == 1)
          ++sw;
        side = 0;
      } else {
        if (side == 0)
          ++sw;
        side = 1;
      }
    }
    std::cout << sw << std::endl;
  }
  return 0;
}