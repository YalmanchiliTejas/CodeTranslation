#include <iostream>
#include <sstream>

int main(int argc, char const* argv[])
{
    int r, g, b;
    std::cin >> r >> g >> b;

    std::stringstream ss;
    ss << r << g << b;

    auto num = std::stoi(ss.str());

    if (num % 4 == 0) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}