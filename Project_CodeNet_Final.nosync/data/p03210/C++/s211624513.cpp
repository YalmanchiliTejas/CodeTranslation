#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    bool y = false;
    if (N == 7 || N == 5 || N == 3) {
        y = true;
    }

    std::cout << ((y)?"YES":"NO") << std::endl;
    return 0;
}