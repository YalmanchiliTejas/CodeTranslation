#include <iostream>
#include <vector>
#include <cmath>

int a()
{
    char a, b, c;
    std::cin >> a >> b >> c;
    
    if(a == b && b == c)
    {
        std::cout << "No";
    }
    else
    {
        std::cout << "Yes";
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    a();
    return 0;
}