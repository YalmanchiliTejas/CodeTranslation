#include <iostream>

int main(void)
{
    int X;
    std::string ans = "No";
    std::cin >> X;

    if(X >= 30)
        ans = "Yes";

    std::cout << ans << std::endl;

    return 0;
}