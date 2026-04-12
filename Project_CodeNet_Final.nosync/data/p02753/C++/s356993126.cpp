#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline(std::cin, str);

    auto has_bus = false;
    for (size_t i = 1; i < str.size(); i += 1) {
        if (str[i] != str[0]) {
            has_bus = true;
            break;
        }
    }

    std::cout << (has_bus ? "Yes" : "No") << "\n";
    return 0;
}
