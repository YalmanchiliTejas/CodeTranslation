#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int n, m;
    
    std::cin >> n >> m;

    if (n == m) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
